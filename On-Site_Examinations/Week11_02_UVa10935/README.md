UVa 10935 - Throwing cards away I

1. Problem Information

* Platform: UVa
* Problem ID: 10935
* Problem Title: Throwing cards away I
* Problem Link: https://onlinejudge.org/external/109/10935.html
* Source Code (Fail): ./src/throwing_cards_fail.cpp
* Source Code (Correct/Accepted): ./src/throwing_cards_accepted.cpp

⸻

2. Problem Description

有一疊卡片編號 1 到 n，依序放入 queue。

進行以下操作直到只剩一張：

操作規則

1. 丟掉最上面的卡片（discard）
2. 將下一張卡片放到最底下（move to bottom）

⸻

輸出

* 所有被丟掉的卡片順序
* 最後剩下的卡片

⸻

3. Solution Idea

核心想法

👉 使用 queue 模擬循環操作

⸻

流程

1. 初始化 queue：1 → n
2. 重複：
    * pop front → discard
    * next front → push back
3. 直到剩 1 張

⸻

4. Pseudocode

START
WHILE read n != 0
    queue q = 1..n
    discarded list
    WHILE q.size > 1
        discard q.front
        pop
        move next front to back
    print discarded
    print remaining
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n;
	while(cin>>n && n!=0){
		queue<int> q;
		for(int i=0; i<n; i++){
			q.push(i+1);
		}
		
		bool last=1;
		
		if(n==1){
			cout<<"Discarded cards:";
			cout<<endl;
		}
		else if(n==2){
			cout<<"Discarded cards: ";
			cout<<q.front()<<endl;
			q.pop();
		}
		else{
			cout<<"Discarded cards: ";
			for(int i=0; i<n-1; i++){
				if(last==1){
					cout<<q.front()<<", ";
					q.pop();
					q.push(q.front());
					q.pop();
						
					if(q.size()==2)last=0;
				}
				else{
					cout<<q.front()<<endl;
					q.pop();
				}
			}
		}
		
		cout<<"Remaining card: "<<q.front()<<endl;
	}
	
	return 0;
}

⸻

6. Why it failed

這份程式其實「大方向正確」，但屬於 hard-coded simulation error-prone 寫法。

⸻

❌ 1. 不必要的 special case

if(n==1) ...
else if(n==2) ...

👉 正確做法：所有 n 都用同一套 loop

⸻

❌ 2. last 控制邏輯不可靠

bool last = 1;

* 用 flag 判斷輸出格式
* 但 queue 狀態才應該是唯一依據
* 容易錯亂

⸻

❌ 3. loop 架構錯誤

for(int i=0; i<n-1; i++)

👉 discard 次數不是固定 n-1，而是「動態直到剩 1 張」

⸻

❌ 4. 輸出格式容易 WA

* comma handling 不乾淨
* edge case（n=1,2）分支多

⸻

7. Correct Code

#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    while(cin >> n && n){
        queue<int> q;
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        cout << "Discarded cards:";
        bool first = true;
        while(q.size() > 1){
            int discarded = q.front();
            q.pop();
            if(first){
                cout << " " << discarded;
                first = false;
            }else{
                cout << ", " << discarded;
            }
            int move = q.front();
            q.pop();
            q.push(move);
        }
        cout << "\nRemaining card: " << q.front() << "\n";
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
structure	special cases	unified loop
correctness	fragile	stable
readability	medium	clean
logic	manual control	pure simulation

⸻

Reflection

* 這題核心：
    👉 queue simulation
* 最大錯誤：
    * 用「條件控制流程」而不是「模擬規則」
* 正確思維：
    👉 永遠讓 queue 自然跑，不要手動切狀態
* UVA simulation 重點：
    * 能 loop 解決就不要 special case