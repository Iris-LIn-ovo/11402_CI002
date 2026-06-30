#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // 如果起點或終點有障礙，直接回傳 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // 初始化起點
        dp[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 跳過起點與障礙物
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i > 0) dp[i][j] += dp[i - 1][j]; // 加上上方格的路徑數
                if (j > 0) dp[i][j] += dp[i][j - 1]; // 加上左方格的路徑數
            }
        }
        
        return (int)dp[m - 1][n - 1];
    }
};
