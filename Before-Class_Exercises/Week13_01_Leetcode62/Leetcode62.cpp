class Solution {
public:
    int uniquePaths(int m, int n) {
        // 使用一維陣列來優化空間，因為當前行只依賴上一行
        vector<int> dp(n, 1);
        
        // 從第二行開始計算
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // dp[j] 原本代表上一行的值 (上方)，dp[j-1] 代表當前行的左方
                dp[j] += dp[j - 1];
            }
        }
        
        return dp[n - 1];
    }
};
