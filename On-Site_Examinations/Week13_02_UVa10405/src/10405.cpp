#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 使用全域變數儲存表格，避免記憶體不足，長度 1000 以內開 1005 很安全
int dp[1005][1005];

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    // 當成功讀取到兩行字串時進行處理
    while (getline(cin, s1) && getline(cin, s2)) {
        int n = s1.length();
        int m = s2.length();

        // 核心邏輯：填表格
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                // 第一行或第一列設為 0 (代表空字串與任何字串的 LCS 皆為 0)
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } 
                // 若字元相同，長度為斜對角數值 + 1
                else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } 
                // 若字元不同，取上方或左方的最大值
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // 最右下角的數值就是答案
        cout << dp[n][m] << endl;
    }
    return 0;
}