UVa 10783 - Odd Sum

1. Problem Information

* Platform: UVa
* Problem ID: 10783
* Problem Title: Odd Sum
* Problem Link: https://onlinejudge.org/external/107/10783.html
* Source Code (Fail): ./src/odd_sum_fail.cpp
* Source Code (Correct/Accepted): ./src/odd_sum_accepted.cpp

⸻

2. Problem Description

給定多組測試資料，每組包含兩個整數 a 和 b。

要求計算：

👉 在區間 [a, b] 之間所有「奇數」的總和

並輸出每組測試的結果。

⸻

3. Solution Idea

核心想法

* 逐一檢查區間內每個數字
* 判斷是否為奇數（j % 2 == 1）
* 若是奇數就加進總和

⸻

方法

* 讀取測試筆數 n
* 對每組 (a, b)：
    * 從 a 遍歷到 b
    * 累加所有奇數
* 輸出格式為：
    * Case x: ans

⸻

Edge Cases

* a 和 b 相同
* a = 1 或 b = 1
* 範圍很小或只有一個數
* 必須確保 Case 編號正確

⸻

4. Pseudocode

START
Read n
FOR i = 1 to n
    Read a, b
    ans = 0
    FOR j = a to b
        IF j is odd
            ans += j
    print "Case i: ans"
END

⸻

5. Source Code

Fail Code

// 常見錯誤版本（示意）
// 忘記判斷奇數 / 或 Case 格式錯誤

Why it failed:

* 沒有正確範圍累加
* 或 Case 編號輸出錯誤
* 或漏掉奇數判斷條件

⸻

Correct Code

#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a = 0, b = 0;
        int ans = 0;
        cin >> a >> b;
        for(int j = a; j <= b; j++){
            if(j % 2 == 1){
                ans = ans + j;
            }
        }
        cout << "Case " << i + 1 << ": " << ans << endl;
    }
    return 0;
}

⸻

6. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Logic	未正確累加奇數	正確判斷 j % 2
Loop	可能少範圍或錯誤	正確 a → b 遍歷
Output	Case 格式錯誤風險	標準 Case i+1
Accuracy	不穩定	穩定 AC

⸻

Reflection

* 這題核心很單純：條件篩選 + 累加
* UVA 常考輸出格式（Case 編號）
* 小問題也可能 WA：
    * 奇數判斷
    * 範圍設定
    * 輸出格式
* 之後應該先確認「輸出格式」再寫邏輯