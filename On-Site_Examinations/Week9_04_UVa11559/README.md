UVa 11559 - Event Planning

1. Problem Information

* Platform: UVa
* Problem ID: 11559
* Problem Title: Event Planning
* Problem Link: https://onlinejudge.org/external/115/11559.html
* Source Code (Fail): ./src/event_planning_fail.cpp
* Source Code (Correct/Accepted): ./src/event_planning_accepted.cpp

⸻

2. Problem Description

你要為一群人安排住宿，目標是在預算內找到最便宜的方案。

⸻

輸入

* n：參加人數
* b：預算
* h：飯店數量
* w：每間飯店有 w 個週末價格/可容納人數

⸻

規則

對每間飯店：

* 有一個「每人價格」
* 有多週的可用床位數
* 如果某週床位 ≥ n，代表可以入住
* 總價 = n × price

⸻

輸出

* 如果有合法飯店且在預算內 → 輸出最小費用
* 否則 → stay home

⸻

3. Solution Idea

核心想法

👉 枚舉所有飯店 + 所有週次

* 檢查是否可容納 n 人
* 計算總價
* 取最小值

⸻

流程

1. 初始化 best = INF
2. 對每個 hotel：
    * 讀 price
    * 檢查每週 beds
    * 如果可住：
        * 更新 best
3. 判斷 best 是否 <= b

⸻

4. Pseudocode

START
WHILE input exists
    read n, b, h, w
    best = INF
    FOR each hotel
        read price
        FOR each week
            read beds
            IF beds >= n
                best = min(best, price * n)
    IF best <= b
        print best
    ELSE
        print "stay home"
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int n,b,h,w;
	while(cin>>n>>b>>h>>w){
		int maxb=b;
		bool havehotel=0;
		
		for(int i=0; i<h; i++){
			int hp;
			cin>>hp;
			int price=hp*n;
			int bednum;
			
			for(int j=0; j<w; j++){
				cin>>bednum;
				if(bednum>=n && price<=maxb){
					maxb=price;
					havehotel=1;
				}
			}
		}
		
		if(havehotel==0){
			cout<<"stay home"<<endl;
		}
		else{
			cout<<maxb<<endl;
		}
	}
	return 0;
}

⸻

Why it failed:

⸻

❌ 1. maxb 命名錯誤（其實是 min cost）

int maxb=b;

👉 這其實應該是 minimum cost, 不是 max

⸻

❌ 2. 更新條件錯誤

if(bednum>=n && price<=maxb)

問題：

* 你在「每個 week」都更新 price
* 但 price 是固定 hotel-level，不應在 loop 內反覆判斷

⸻

❌ 3. 邏輯污染

* hotel 應該只要「存在一週可住」就算
* 你卻在每一週重複更新 cost

⸻

❌ 4. 沒有 clean best solution structure

⸻

6. Correct Code

#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n, b, h, w;
    while(cin >> n >> b >> h >> w){
        int best = INT_MAX;
        for(int i = 0; i < h; i++){
            int price;
            cin >> price;
            bool ok = false;
            for(int j = 0; j < w; j++){
                int beds;
                cin >> beds;
                if(beds >= n){
                    ok = true;
                }
            }
            if(ok){
                best = min(best, price * n);
            }
        }
        if(best <= b)
            cout << best << endl;
        else
            cout << "stay home" << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Logic level	per-week update	per-hotel evaluation
Variable meaning	confusing	clear
correctness	unstable	stable
structure	mixed	clean

⸻

Reflection

* 這題核心：
    👉 simulation + filtering
* 最大錯誤：
    * 把 hotel-level decision 放進 week loop
* 正確思維：
    👉 “先判斷可行性，再算 cost”
* UVA 常見：
    * input nested loop 很容易寫亂