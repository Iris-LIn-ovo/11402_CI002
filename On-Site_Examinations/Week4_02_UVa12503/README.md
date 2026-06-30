UVa 12503 - Robot Instructions

1. Problem Information

* Platform: UVa
* Problem ID: 12503
* Problem Title: Robot Instructions
* Problem Link: https://onlinejudge.org/external/125/12503.html
* Source Code (Fail): ./src/robot_fail.cpp
* Source Code (Correct/Accepted): ./src/robot_accepted.cpp

⸻

2. Problem Description

有一個機器人依照指令移動：

* LEFT → 往左移（-1）
* RIGHT → 往右移（+1）
* SAME AS i → 重複第 i 條指令

目標是計算所有指令執行完後，機器人的最終位置。

⸻

3. Solution Idea

核心想法

* 用 vector 記錄每一條指令的「移動值」
* 每次指令轉換成：
    * LEFT → -1
    * RIGHT → +1
    * SAME AS i → 複製第 i-1 個指令結果
* 同時維護目前位置 pos

⸻

重點觀念

* SAME AS i 不是重新計算字串
* 而是直接「複製之前算好的結果」
* 所以可以 O(1) 取得歷史結果

⸻

Edge Cases

* i 是 1-based index（要轉成 i-1）
* 指令數最多 N
* 每組 testcase 要重置 pos

⸻

4. Pseudocode

START
Read T
FOR each test case
    Read n
    vector stap
    pos = 0
    FOR i = 1 to n
        Read instruction
        IF LEFT
            value = -1
            pos -= 1
        ELSE IF RIGHT
            value = +1
            pos += 1
        ELSE (SAME AS x)
            value = stap[x - 1]
            pos += value
        push value into stap
    print pos
END

⸻

5. Source Code

Fail Code

// 常見錯誤版本（示意）
// 沒有處理 SAME AS 的位置更新 / 或輸出遺失

Why it failed:

* 沒有輸出結果（你原碼缺 cout）
* SAME AS i 若沒有同步更新 pos 會錯
* 容易漏掉每組 testcase 的初始化

⸻

Correct Code

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int n;
        cin >> n;
        vector<int> stap;
        int pos = 0;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(s == "LEFT"){
                stap.push_back(-1);
                pos--;
            }
            else if(s == "RIGHT"){
                stap.push_back(1);
                pos++;
            }
            else{
                string as;
                int x;
                cin >> as >> x;
                stap.push_back(stap[x - 1]);
                pos += stap[x - 1];
            }
        }
        cout << pos << endl;
    }
    return 0;
}

⸻

6. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Output	沒輸出 final pos	正確輸出 pos
SAME AS	只存沒應用	正確累加 pos
Logic	不完整	完整模擬
Test Case	可能少 reset	每次重置 pos

⸻

Reflection

* 這題核心是「記錄歷史結果」
* SAME AS 類題要注意：
    * 不能重新解析字串
    * 要直接用已存結果
* 很容易漏掉：
    * pos 更新
    * 輸出結果
    * testcase 分段處理