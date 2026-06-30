UVa 12405 - Scarecrow

1. Problem Information

* Platform: UVa
* Problem ID: 12405
* Problem Title: Scarecrow
* Problem Link: https://onlinejudge.org/external/124/12405.html
* Source Code (Fail): ./src/scarecrow_fail.cpp
* Source Code (Correct/Accepted): ./src/scarecrow_accepted.cpp

⸻

2. Problem Description

給你一條農田（用字串表示），其中：

* . 表示空地（需要保護）
* # 表示障礙物（不需要保護）

⸻

規則

你要放稻草人（scarecrow）：

* 每個稻草人可以保護自己位置 + 左右各 1 格
* 目標是覆蓋所有 .
* 求最少稻草人數

⸻

3. Solution Idea

核心觀念

👉 Greedy + skip coverage

⸻

關鍵策略

從左到右掃描：

* 遇到 . → 放稻草人
* 這個稻草人可以覆蓋 i, i+1, i+2
* 所以 i += 3
* 遇到 # → i++

⸻

4. Pseudocode

for each test case:
    read n
    read string s
    i = 0
    count = 0
    while i < n:
        if s[i] == '.':
            count++
            i += 3
        else:
            i++
    print count

⸻

5. Source Code

Fail Code

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
	int N;
	cin>>N;
	for(int n=0; n<N; n++){
		cout<<"Case "<<n+1<<": ";
		int x;
		cin>>x;
		string a[x];
		for(int i=0; i<x; i++){
			cin>>a[i];
		}
		int l=0,r=0;
		while(l!=x){
			for
		}
		
	}
	return 0;
}

⸻

6. Why it failed

這份 code 的問題是：

⸻

❌ 1. 還沒寫完核心邏輯

while(l!=x){
    for
}

👉 完全缺少：

* greedy rule
* coverage logic

⸻

❌ 2. input 型態錯誤

string a[x];

👉 題目是：

* 一條 string
* 不是 string array

⸻

❌ 3. 沒有 modeling problem

你還停留在：

👉 array traversal（未完成）

但正確是：

👉 interval coverage (i, i+1, i+2)

⸻

7. Correct Code

#include <iostream>
#include <string>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int n;
        string s;
        cin >> n >> s;
        int i = 0;
        int ans = 0;
        while(i < n){
            if(s[i] == '.'){
                ans++;
                i += 3;   // scarecrow covers i, i+1, i+2
            }else{
                i++;
            }
        }
        cout << "Case " << tc << ": " << ans << "\n";
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
input	string array	single string
logic	incomplete	greedy skip
idea	missing	coverage i+3
correctness	WA	AC

⸻

Reflection

* 這題核心：
    👉 greedy skip coverage
* 關鍵技巧：
    * 一旦放稻草人 → 直接跳 3 格
* 常見錯誤：
    * 把 greedy 寫成 simulation but not simplified