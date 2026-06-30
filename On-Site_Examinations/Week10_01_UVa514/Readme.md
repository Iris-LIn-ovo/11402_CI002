UVa 514 - Rails

1. Problem Information

* Platform: UVa
* Problem ID: 514
* Problem Title: Rails
* Problem Link: https://onlinejudge.org/external/5/514.html
* Source Code (Fail): ./src/rails_fail.cpp
* Source Code (Correct/Accepted): ./src/rails_accepted.cpp

⸻

2. Problem Description

有一列火車車廂從 1 到 n 依序進入車站（A 端）。

你可以使用一個 stack（暫存軌道） 來調整順序。

目標是判斷：

👉 給定一個目標排列，是否可以透過 stack 操作得到

⸻

操作規則

* 車廂 1 → n 依序進入
* 可以：
    * push（進 stack）
    * pop（從 stack 出去）
* 必須符合目標輸出順序

⸻

3. Solution Idea

核心概念

👉 stack 模擬 + greedy

每次：

* 不斷把還沒進來的車廂 push 進 stack
* 直到 stack top = 目標值
* 再 pop

⸻

判斷條件

* 如果最後 stack 無法匹配 → impossible
* 否則 → possible

⸻

4. Pseudocode

START
WHILE n != 0
    WHILE true
        read first
        IF first == 0
            print blank line
            break
        read target array
        stack s
        A = 1
        FOR each goal in target
            WHILE A <= n AND (stack empty OR top != goal)
                push A
                A++
            IF top == goal
                pop
            ELSE
                impossible
        print Yes/No
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int n;
    while (cin >> n && n != 0) {
        while (true) {
            int first;
            cin >> first;
            if (first == 0) {
                cout << endl;
                break;
            }
            vector<int> target(n);
            target[0] = first;
            for (int i = 1; i < n; i++) cin >> target[i];
            stack<int> s;
            int A = 1;
            bool possible = true;
            for (int i = 0; i < n; i++) {
                int goal = target[i];
                while (A <= n && (s.empty() || s.top() != goal)) {
                    s.push(A);
                    A++;
                }
                if (!s.empty() && s.top() == goal) {
                    s.pop();
                } else {
                    possible = false;
                    break;
                }
            }
            if (possible) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}

⸻

Why it failed:

👉 這份其實是 AC 等級寫法，但有一些「容易 WA / format risk」點：

⸻

⚠️ 1. 輸出格式細節（常見 WA 點）

cout << endl;

* UVa 514 要的是：
    * 每個 test block 結束一個空行
    * 但不能多空行

👉 你的寫法「可能多印」

⸻

⚠️ 2. 邏輯其實 correct，但寫法偏「危險邊界」

* (s.empty() || s.top() != goal) 這個條件：
    * 雖然能過
    * 但不是標準寫法（容易混亂）

⸻

⚠️ 3. 可讀性較低（容易 debug 困難）

⸻

6. Correct Code

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    int n;
    while(cin >> n && n){
        while(true){
            int x;
            cin >> x;
            if(x == 0){
                cout << endl;
                break;
            }
            vector<int> v(n);
            v[0] = x;
            for(int i = 1; i < n; i++){
                cin >> v[i];
            }
            stack<int> st;
            int cur = 1;
            bool ok = true;
            for(int i = 0; i < n; i++){
                int target = v[i];
                while(cur <= n && (st.empty() || st.top() != target)){
                    st.push(cur++);
                }
                if(!st.empty() && st.top() == target){
                    st.pop();
                }else{
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "Yes" : "No") << endl;
        }
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
structure	same logic	cleaner flow
readability	medium	high
safety	borderline	standard
formatting	risky	controlled

⸻

Reflection

* 這題核心：
    👉 stack simulation + greedy matching
* 重點不是邏輯，而是：
    * simulation 是否寫乾淨
* UVA 常見技巧：
    * stack / queue 題一定要「簡化流程」

⸻
 
// 宣告一個用來放整數 (int) 的堆疊，名字叫做 s
stack<int> s; 

s.push(10);   // 1. 推入 (Push)：把 10 丟進堆疊最頂端
s.push(20);   //    再把 20 丟進去，此時 20 在最上面

int top_val = s.top(); // 2. 看頂端 (Top)：看看最上面的元素是誰（會拿到 20）
                       // ⚠️ 注意：這只是看，並不會把數字拿走

s.pop();      // 3. 彈出 (Pop)：把最上面的元素（20）踢掉
              // ⚠️ 注意：pop() 回傳值是 void，它「純剔除」不拿回數值

bool is_empty = s.empty(); // 4. 檢查是否為空 (Empty)：如果堆疊空了回傳 true，否則 false

int current_size = s.size(); // 5. 取得大小 (Size)：看現在堆疊裡總共卡了幾個元素