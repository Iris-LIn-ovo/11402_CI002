UVa 10405 - Longest Common Subsequence

1. Problem Information

* Platform: UVa
* Problem ID: 10405
* Problem Title: Longest Common Subsequence
* Problem Link: https://onlinejudge.org/external/104/10405.html
* Source Code (Fail): ./src/lcs_fail.cpp
* Source Code (Correct/Accepted): ./src/lcs_accepted.cpp

⸻

2. Problem Description

給定兩個字串 s1 與 s2，要求找出：

👉 Longest Common Subsequence (LCS) 的長度

⸻

LCS 定義

在不改變字元順序的前提下：

* 找兩個字串共有的「子序列」
* 不是子字串（不需要連續）

⸻

3. Solution Idea

核心想法

👉 使用 Dynamic Programming（DP）

⸻

DP 定義

dp[i][j] = s1 前 i 個字元 與 s2 前 j 個字元的 LCS 長度

⸻

轉移方程

1. 字元相同

dp[i][j] = dp[i-1][j-1] + 1

2. 字元不同

dp[i][j] = max(dp[i-1][j], dp[i][j-1])

⸻

4. Pseudocode

START
WHILE read s1 and s2
    FOR i = 0..n
        FOR j = 0..m
            IF i==0 OR j==0
                dp[i][j] = 0
            ELSE IF s1[i-1] == s2[j-1]
                dp[i][j] = dp[i-1][j-1] + 1
            ELSE
                dp[i][j] = max(up, left)
    print dp[n][m]
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 使用全域變數儲存表格，避免記憶體不足，長度 1000 以內開 1005 很安全
int dp[1005][1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        int n = s1.length();
        int m = s2.length();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } 
                else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } 
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        cout << dp[n][m] << endl;
    }
    return 0;
}

⸻

6. Why it failed

這份其實是：

👉 AC 等級標準 LCS 解法

但可以指出幾個「潛在問題 / 不最佳化點」：

⸻

⚠️ 1. 每次重新初始化整張 dp

for (i <= n, j <= m)

* 每次 O(nm)
* 沒有 reuse
* 但 UVa 10405 input 小 → OK

⸻

⚠️ 2. getline 沒處理空行 edge case

* UVa 有時會有空字串
* 但這份寫法仍安全

⸻

⚠️ 3. 空間可以優化

* dp[1005][1005] OK
* 但可壓縮成 1D DP

⸻

👉 總結：
✔ 這份不是錯，是「標準 DP 解」

⸻

7. Correct Code (Optimized Version)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1005][1005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    while(getline(cin, a) && getline(cin, b)){
        int n = a.size();
        int m = b.size();
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[n][m] << "\n";
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
correctness	correct	correct
structure	good	same
optimization	none needed	same
complexity	O(nm)	O(nm)

⸻

Reflection

* 這題核心：
    👉 DP table filling (LCS)
* 重點不是寫法，而是：
    * DP recurrence
* UVA LCS 類型特點：
    * 模板化極高
    * 幾乎背公式即可