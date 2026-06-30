UVa 11292 - Dragon of Loowater

1. Problem Information

* Platform: UVa
* Problem ID: 11292
* Problem Title: Dragon of Loowater
* Problem Link: https://onlinejudge.org/external/112/11292.html
* Source Code (Fail): ./src/dragon_loowater_fail.cpp
* Source Code (Correct/Accepted): ./src/dragon_loowater_accepted.cpp

⸻

2. Problem Description

你有 n 隻龍頭（dragon heads）和 m 位騎士（knights）。

⸻

規則

* 每個龍頭需要被「砍掉」
* 每位騎士只能砍一個龍頭
* 騎士的能力值必須 ≥ 龍頭大小才可以砍
* 每個騎士只能用一次
* 要付的代價 = 使用騎士能力值總和

⸻

目標

👉 找出「最小總花費」來殺光所有龍頭
👉 如果無法全部殺完 → 輸出：

Loowater is doomed!

⸻

3. Solution Idea

核心觀念

👉 Greedy + two pointers

⸻

正確策略

1. 龍頭排序（小 → 大）
2. 騎士排序（小 → 大）
3. 用最小能打的騎士去打當前龍頭

⸻

為什麼？

👉 因為：

* 小龍頭用小騎士最省
* 大騎士留給大龍頭

⸻

4. Pseudocode

sort dragons
sort knights
i = 0, j = 0
cost = 0
while i < n and j < m:
    if knight[j] >= dragon[i]:
        cost += knight[j]
        i++
    j++
if i < n:
    print doom
else:
    print cost

⸻

5. Source Code

Fail Code

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0 && m==0)break;
		vector<int> dragon;
		vector<int> knight;
		
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			dragon.push_back(x);
		}
		for(int i=0; i<m; i++){
			int x;
			cin>>x;
			knight.push_back(x);
		}
		
		sort(dragon.begin(), dragon.end());
		sort(knight.begin(), knight.end());
		int sum=0;
		bool allkill=1;
		//2 7
		//1 2 5 8
		for(int i=0; i<dragon.size(); i++){
			bool iskill=0;
			for(int j=0; j<knight.size(); j++){
				if(dragon[i]<=knight[j]){
					sum+=knight[j];
					knight[j]=-1;
					iskill=1;
					break;
				}
			}
		
			if(iskill==0){
				allkill=0;
			}
		}
		
		if(allkill==0){
			cout<<"Loowater is doomed!"<<endl;
		}
		else{
			cout<<sum<<endl;
		}
	}
	return 0;
}

⸻

6. Why it failed

這份 code 的問題是「能跑，但不是最優解」。

⸻

❌ 1. Greedy 方向正確，但選法錯誤

你現在是：

for each dragon → scan all knights

👉 問題：

* 沒有 pointer 推進
* 沒有保證「最小可用 knight」

⸻

❌ 2. greedy 不完整（浪費更小解）

因為你：

* 每次從頭掃 knight
* 但沒有控制 index 移動

👉 可能導致：

* 錯過更優匹配順序
* O(n*m) 過慢

⸻

❌ 3. -1 標記不安全

knight[j] = -1;

👉 問題：

* 破壞排序
* 影響後續匹配邏輯

⸻

❌ 4. 沒有 two pointers 思維

這題本質是：

👉 matching problem (sorted greedy pairing)

⸻

7. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        vector<int> dragon(n), knight(m);
        for(int i = 0; i < n; i++){
            cin >> dragon[i];
        }
        for(int i = 0; i < m; i++){
            cin >> knight[i];
        }
        sort(dragon.begin(), dragon.end());
        sort(knight.begin(), knight.end());
        int i = 0, j = 0;
        long long cost = 0;
        while(i < n && j < m){
            if(knight[j] >= dragon[i]){
                cost += knight[j];
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i < n){
            cout << "Loowater is doomed!\n";
        }else{
            cout << cost << "\n";
        }
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
strategy	nested loop	two pointers
efficiency	O(nm)	O(n log n)
correctness	risky greedy	optimal greedy
structure	manual marking	clean matching

⸻

Reflection

* 這題核心：
    👉 sorted greedy matching
* 最大問題：
    * 沒有 pointer 移動
    * 沒有「全域最小匹配策略」
* 正確觀念：
    👉 greedy + sorted = two pointers 幾乎是標準解