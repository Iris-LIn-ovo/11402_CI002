UVa 540 - Team Queue

1. Problem Information

* Platform: UVa
* Problem ID: 540
* Problem Title: Team Queue
* Problem Link: https://onlinejudge.org/external/5/540.html
* Source Code (Fail): ./src/team_queue_fail.cpp
* Source Code (Correct/Accepted): ./src/team_queue_accepted.cpp

⸻

2. Problem Description

模擬一個特殊排隊系統：

規則

* 每個人屬於一個 team
* 排隊時遵守：
    1. 同 team 的人必須連續排在一起
    2. 不同 team 依照「第一次進入隊列的順序」

⸻

操作

* ENQUEUE x：將人 x 加入隊列
* DEQUEUE：從隊列前端移除一人
* STOP：結束

⸻

3. Solution Idea

核心想法

👉 使用 兩層 queue 結構

* queue<queue<int>>
    * 外層：team 順序
    * 內層：每個 team 的人

⸻

關鍵技巧

* team_id[x]：紀錄人屬於哪個 team
* line：記錄 team 出現順序
* teamline[id]：該 team 的人

⸻

操作流程

ENQUEUE x

1. 找 team id
2. 如果 team 第一次出現 → push 到 line
3. 加入 team queue

DEQUEUE

1. 取 line front team
2. pop 該 team 一個人
3. 若 team empty → pop team

⸻

4. Pseudocode

START
WHILE read n != 0
    read teams
    build team_id mapping
    line queue (team order)
    team queues
    WHILE command != STOP
        IF ENQUEUE x
            add to team queue
            if first member → push team to line
        IF DEQUEUE
            output front of first team
            remove from that team
            if empty → pop team
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n,case_num=1;
	int team_id[1000005];
	while(cin>>n && n!=0){
		cout<<"Scenario #"<<case_num<<endl;
		case_num++;
		
		for(int i=0; i<n; i++){
			int num;
			cin>>num;
			for(int j=0; j<num; j++){
				int x;
				cin>>x;
				team_id[x]=i;
			}
		}
		
		string step;
		queue<int> line;
		vector<queue<int> > teamline(n);
		
		while(cin>>step && step!="STOP"){
			if(step=="DEQUEUE"){
				int now=line.front();
				cout<<teamline[now].front()<<endl;
				teamline[now].pop();
				if(teamline[now].empty()){
					line.pop();
				}
			}
			else if(step=="ENQUEUE"){
				int x;
				cin>>x;
				int id=team_id[x];
				if(teamline[id].empty()){
					line.push(id);
				}
				teamline[id].push(x);
			}
		}
		cout<<endl;
	}
	
	return 0;
}

⸻

6. Why it failed (or risk points)

這題其實邏輯是 AC 等級，但有幾個隱藏風險點：

⸻

⚠️ 1. team_id 沒初始化

int team_id[1000005];

* 沒清空
* 多 case 時可能污染上一組資料

👉 正確應該 reset 或重新建構

⸻

⚠️ 2. 沒處理空隊列安全性

int now = line.front();

* 假設 line 不空
* 若資料錯誤可能 RE

⸻

⚠️ 3. include 重複

#include <vector>
#include <vector>

* 不影響 AC，但不乾淨

⸻

⚠️ 4. 設計其實是正確但「初始化習慣不佳」

⸻

7. Correct Code

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    int n, caseNum = 1;
    while(cin >> n && n){
        cout << "Scenario #" << caseNum++ << "\n";
        unordered_map<int,int> team_id;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            for(int j = 0; j < k; j++){
                int x;
                cin >> x;
                team_id[x] = i;
            }
        }
        queue<int> teamOrder;
        vector<queue<int>> teamQueue(n);
        string cmd;
        while(cin >> cmd && cmd != "STOP"){
            if(cmd == "ENQUEUE"){
                int x;
                cin >> x;
                int t = team_id[x];
                if(teamQueue[t].empty()){
                    teamOrder.push(t);
                }
                teamQueue[t].push(x);
            }
            else{
                int t = teamOrder.front();
                cout << teamQueue[t].front() << "\n";
                teamQueue[t].pop();
                if(teamQueue[t].empty()){
                    teamOrder.pop();
                }
            }
        }
        cout << "\n";
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
initialization	risk	safe
structure	correct	same
robustness	medium	high
clarity	ok	cleaner

⸻

Reflection

* 這題核心：
    👉 queue of queues
* 重點不是難度，而是：
    * state management
* UVA simulation 題常見陷阱：
    * 沒 reset data
    * 假設 input clean