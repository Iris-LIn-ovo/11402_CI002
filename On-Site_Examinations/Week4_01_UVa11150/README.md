UVa 11150 - Cola

1. Problem Information

* Platform: UVa
* Problem ID: 11150
* Problem Title: Cola
* Problem Link: https://onlinejudge.org/external/111/11150.html
* Source Code (Fail): ./src/cola_fail.cpp
* Source Code (Correct/Accepted): ./src/cola_accepted.cpp

⸻

2. Problem Description

你有 n 個空瓶子，可以用來換可樂：

* 每 3 個空瓶可以換 1 瓶可樂
* 喝完可樂後會再得到 1 個空瓶
* 可以重複兌換

目標是計算最多可以喝到幾瓶可樂。

⸻

3. Solution Idea

核心概念

* 每次用空瓶兌換可樂
* 喝完後會增加新的空瓶
* 不斷重複直到不能再換

⸻

流程

* empty 代表目前空瓶數
* count 代表喝到的可樂數
* 每次：
    * 用 empty / 3 換可樂
    * 更新剩餘空瓶 empty % 3
    * 加上喝完後新增的空瓶

⸻

Edge Cases

* 剛好不能換（<3）
* 剩 2 個瓶子可「借瓶」再換一次（特殊情況）
* 小輸入 n ≤ 200

⸻

4. Pseudocode

START
WHILE input exists
    Read n
    empty = n
    count = n
    WHILE empty >= 3
        a = empty / 3
        b = empty % 3
        count += a
        empty = a + b
    IF empty == 2
        print count + 1
    ELSE
        print count
END

⸻

5. Source Code

Fail Code

// 常見錯誤版本（示意）
// 沒考慮借瓶子 / 或循環條件錯誤

Why it failed:

* 沒處理剩 2 個瓶子的特殊情況
* 或更新 empty 的方式錯誤
* 或循環條件不完整導致結果偏差

⸻

Correct Code

#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        int count = n, empty = n;
        int a, b;
        while(empty >= 3 && n <= 200){
            a = empty / 3;
            b = empty % 3;
            count += a;
            empty = b + a;
        }
        if(empty == 2)
            cout << count + 1 << endl; // 最多借一個瓶子
        else
            cout << count << endl;
    }
    return 0;
}

⸻

6. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Logic	未完整模擬兌換	正確模擬 + 特殊情況
Edge Case	忽略借瓶	empty == 2 補償
Loop Control	可能錯誤更新	正確 empty 更新
Accuracy	不穩定	AC

⸻

Reflection

* 這題本質是「模擬 + 規則更新」
* 關鍵在：
    * 每次兌換後空瓶如何變化
* 特殊情況（借瓶）很容易漏掉
* UVA 題常見：
    * 主流程簡單
    * hidden edge case 很重要