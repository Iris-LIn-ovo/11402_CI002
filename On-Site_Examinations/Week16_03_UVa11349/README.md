UVa 11349 - Symmetric Matrix

1. Problem Information

* Platform: UVa
* Problem ID: 11349
* Problem Title: Symmetric Matrix
* Problem Link: https://onlinejudge.org/external/113/11349.html
* Source Code (Fail): ./src/symmetric_matrix_fail.cpp
* Source Code (Correct/Accepted): ./src/symmetric_matrix_accepted.cpp

⸻

2. Problem Description

判斷一個 n × n 矩陣是否為 中心對稱矩陣（symmetric matrix）。

⸻

判斷條件

矩陣必須同時滿足：

1. 所有元素皆為 非負數
2. 對所有位置成立：

[
a[i][j] = a[n-1-i][n-1-j]
]

👉 也就是 以中心點 180 度旋轉對稱

⸻

3. Solution Idea

核心觀念

👉 mirror check (i, j) ↔ (n-1-i, n-1-j)

⸻

重點

只要檢查「一半矩陣」即可：

* 上半部 vs 下半部
* 左半部 vs 右半部

⸻

4. Pseudocode

FOR each test case:
    read n
    read matrix
    ok = true
    FOR i in [0..n-1]
        FOR j in [0..n-1]
            IF a[i][j] < 0 OR a[i][j] != a[n-1-i][n-1-j]
                ok = false
    print result

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int main(){
	int N;
	cin>>N;
	for(int s=0; s<N; s++){
		char n1,n2;
		cin>>n1>>n2;
		int n;
		cin>>n;
		
		bool issym=1;
		long long a[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>a[i][j];
				if(a[i][j]<0)issym=0;
			}
		}
		
		int mid=n/2;
		if(issym==1){
			if(n==1){
				if(a[0][0]<0)issym=0;
			}
			else{
				if(n%2==1){
					// if(a[mid][mid]!=0)issym=0;
					for(int i=0; i<mid; i++){
						for(int j=0; j<n; j++){
							if(a[i][j]!=a[n-1-i][n-1-j])issym=0;
						}
					}
					for(int j=0; j<mid; j++){
						if(a[mid][j]!=a[mid][n-1-j])issym=0;
					}
				}
				else{
					for(int i=0; i<n; i++){
						for(int j=0; j<n; j++){
							if(a[i][j]!=a[n-1-i][n-1-j])issym=0;
						}
					}
				}
				
			}
		}
		
		cout<<"Test #"<<s+1;
		if(issym==1){
			cout<<": Symmetric."<<endl;
		}
		else{
			cout<<": Non-symmetric."<<endl;
		}
	}
	return 0;
}

⸻

6. Why it failed

這份 code 概念接近正解，但邏輯過度複雜且不正確簡化。

⸻

❌ 1. 不必要的特殊 case（n 奇偶）

if(n % 2 == 1) { ... }
else { ... }

👉 錯誤原因：

* 中心對稱公式對所有 n 都一樣
* 不需要分奇偶

⸻

❌ 2. 多餘分段檢查

for(i < mid)
for(j < mid)

👉 問題：

* 只檢查部分矩陣
* 會漏掉非對稱位置

⸻

❌ 3. 邏輯不完整

if(n%2==1) ... else ...

👉 但正確應該：

👉 全部 (i,j) 都要檢查

⸻

❌ 4. VLA（非標準 C++）

long long a[n][n];

👉 可能 WA / CE（某些 OJ）

⸻

❌ 5. unnecessary complexity

* mid
* special row handling
* extra loops

👉 本題其實是 1 個公式解決

⸻

7. Correct Code

#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        string dummy;
        cin >> dummy; // "N="
        int n;
        cin >> n;
        long long a[105][105];
        bool ok = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
                if(a[i][j] < 0) ok = false;
            }
        }
        for(int i = 0; i < n && ok; i++){
            for(int j = 0; j < n && ok; j++){
                if(a[i][j] != a[n-1-i][n-1-j]){
                    ok = false;
                }
            }
        }
        cout << "Test #" << tc << ": ";
        cout << (ok ? "Symmetric." : "Non-symmetric.") << "\n";
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
logic	split cases	single formula
checking	partial	full matrix
complexity	messy	simple
correctness	risky	AC

⸻

Reflection

* 這題核心：
    👉 one-line symmetry condition
* 最大問題：
    * 把簡單條件拆成 case handling
* 正確思維：
    👉 所有 (i,j) 都用同一條 rule