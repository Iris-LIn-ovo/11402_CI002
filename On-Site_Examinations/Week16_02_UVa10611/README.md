UVa 10611 - The Playboy Chimp

1. Problem Information

* Platform: UVa
* Problem ID: 10611
* Problem Title: The Playboy Chimp
* Problem Link: https://onlinejudge.org/external/106/10611.html
* Source Code (Fail): ./src/playboy_chimp_fail.cpp
* Source Code (Correct/Accepted): ./src/playboy_chimp_accepted.cpp

⸻

2. Problem Description

給定一個已排序的身高列表（chimp heights），以及多個查詢值（Luchu height）。

⸻

每次查詢要輸出：

* 最高但 < query 的人
* 最低但 > query 的人

如果不存在則輸出 X

⸻

3. Solution Idea

核心觀念

👉 Binary Search（lower_bound / upper_bound）

⸻

關鍵

對於每個 b：

* 左邊：最大 < b
* 右邊：最小 > b

⸻

4. Pseudocode

sort g
FOR each query b:
    idx = lower_bound(g, b)
    right = first element > b
    left = last element < b
    print left or X
    print right or X

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
	int girln,boyn;
	cin>>girln;
	int g[girln];
	for(int i=0; i<girln; i++){
		cin>>g[i];
	}
	cin>>boyn;
	for(int i=0; i<boyn; i++){
		int b;
		cin>>b;
		if(b<g[0]){
			cout<<"X "<<g[0]<<endl;
		}
		else if(b>g[girln-1]){
			cout<<g[girln-1]<<" X"<<endl;
		}
		else if(b==g[0]){
			bool findbig=0;
			for(int j=0; j<girln; j++){
				if(g[j]>b){
					cout<<"X "<<g[j]<<endl;
					findbig=1;
					break;
				}
			}
			if(findbig==0)cout<<"X X"<<endl;
		}
		else if(b==g[girln-1]){
			bool findsmall=0;
			for(int j=0; j<girln; j++){
				if(g[girln-1-j]<b){
					cout<<g[j]<<" X"<<endl;
					findsmall=1;
					break;
				}
			}
			if(findsmall==0)cout<<"X X"<<endl;
		}
		else{
			int min=-1,max=g[girln-1];
			for(int j=0; j<girln; j++){
				if(b>g[j] && g[j]>min){
					min=g[j];
				}
				if(b<g[j] && g[j]<max){
					max=g[j];
				}
			}	
			cout<<min<<" "<<max<<endl;
		}
		
		
	}
	
	return 0;
}

⸻

6. Why it failed

這份 code 的問題不是小 bug，而是「分類式暴力思維」。

⸻

❌ 1. 沒有使用 binary search

你現在是：

掃整個 array 找 min/max

👉 正確應該：

* lower_bound
* upper_bound

⸻

❌ 2. case 分太細但不完整

if (b < g[0]) ...
else if (b > g[n-1]) ...
else if (b == g[0]) ...
else if (b == g[n-1]) ...

👉 問題：

* 沒處理一般 case 的 clean logic
* case overlap 很容易錯

⸻

❌ 3. 邏輯錯誤（min/max 初值）

int min = -1, max = g[girln-1];

👉 會導致：

* min 不正確更新
* max 邏輯混亂

⸻

❌ 4. redundant loops

for j in all elements

👉 本題其實 O(log n) 可以解

⸻

7. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> g(n);
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }
    sort(g.begin(), g.end());
    int q;
    cin >> q;
    while(q--){
        int b;
        cin >> b;
        auto it = lower_bound(g.begin(), g.end(), b);
        // left (max < b)
        if(it == g.begin()){
            cout << "X ";
        }else{
            cout << *(it - 1) << " ";
        }
        // right (min > b)
        if(it == g.end()){
            cout << "X\n";
        }else{
            if(*it == b){
                auto it2 = upper_bound(g.begin(), g.end(), b);
                if(it2 == g.end()) cout << "X\n";
                else cout << *it2 << "\n";
            }else{
                cout << *it << "\n";
            }
        }
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
method	brute scan	binary search
complexity	O(nq)	O(q log n)
structure	many cases	unified logic
correctness	risky	stable

⸻

Reflection

* 這題核心：
    👉 sorted array + binary search
* 最大問題：
    * 用「分類 if-else」取代「數學定位」
* 正確觀念：
    👉 看到 sorted + query = binary search