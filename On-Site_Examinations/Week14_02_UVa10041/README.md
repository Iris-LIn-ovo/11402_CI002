UVa 10041 - Vito’s Family

1. Problem Information

* Platform: UVa
* Problem ID: 10041
* Problem Title: Vito’s Family
* Problem Link: https://onlinejudge.org/external/100/10041.html
* Source Code (Fail): ./src/vitos_family_fail.cpp
* Source Code (Correct/Accepted): ./src/vitos_family_accepted.cpp

⸻

2. Problem Description

給定一組親戚的住址（整數座標），需要找出一個「最佳會面點」，讓所有人走到該點的總距離最小。

⸻

距離定義

👉 使用 絕對距離

|a - x|

⸻

任務

找到一個位置 x，使：

sum(|ai - x|)

最小

⸻

3. Solution Idea

核心觀念

👉 中位數（median）

⸻

為什麼是中位數？

在 1D 距離最小化問題中：

* 最佳解 = median
* 不需要 try 所有點

⸻

4. Pseudocode

FOR each test case
    read n
    read array
    sort array
    median = v[n/2]
    sum = 0
    FOR each element
        sum += abs(v[i] - median)
    print sum
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int N;
	cin>>N;
	for(int s=0; s<N; s++){
		int n;
		cin>>n;
		vector<int> v;
		for(int i=0; i<n;i++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int mid=v.size()/2;
		
		int total=0;
		if(n%2==1){
			for(int i=0; i<v.size()-1; i++){
				if(i!=mid){
					int count=v[i]-v[mid];
					if(count<0){
						total-=count;
					}
					else{
						total+=count;
					}
				}
			}
		}
		else{
			int count1=0, count2=0;
			for(int i=0; i<v.size()-1; i++){
				if(i!=mid){
					int count=v[i]-v[mid];
					if(count<0){
						count1-=count;
					}
					else{
						count1+=count;
					}
				}
			}
			for(int i=0; i<v.size(); i++){
				if(i!=mid-1){
					int count=v[i]-v[mid-1];
					if(count<0){
						count2-=count;
					}
					else{
						count2+=count;
					}
				}
			}
			if(count1<count2){
				total+=count1;
			}
			else{
				total+=count2;
			}
		}
		cout<<total<<endl;
	}
	return 0;
}

⸻

6. Why it failed

這份 code 的問題不是小 bug，而是：

⸻

❌ 1. 把「median 性質問題」寫成 case analysis

if(n % 2 == 1) ...
else ...

👉 其實：

* n 奇數/偶數都一樣
* 不需要分兩種情況

⸻

❌ 2. distance 計算寫得太複雜

if(count < 0) ...

👉 本質應該是：

abs(v[i] - median)

⸻

❌ 3. 多餘比較 median1 / median2

count1 vs count2

👉 偶數時其實兩個 median 都可以
👉 但直接取其中一個即可（或兩者都可）

⸻

❌ 4. 邏輯過度工程化

* 把簡單 median 問題寫成分支 + brute force

⸻

7. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int median = v[n / 2];
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(v[i] - median);
        }
        cout << ans << "\n";
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
idea	split cases	median theorem
complexity	messy	clean
math insight	missing	correct
implementation	overcomplicated	simple

⸻

Reflection

* 這題核心：
    👉 1D absolute distance minimization
* 關鍵觀念：
    * 不要 brute force
    * 直接用 median
* UVA 常見陷阱：
    👉 「數學題被寫成 simulation」