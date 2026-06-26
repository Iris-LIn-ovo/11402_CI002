class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue; // 起點不變
                
                if (i == 0) {
                    // 第一行：只能從左邊累積
                    grid[i][j] += grid[i][j - 1];
                } else if (j == 0) {
                    // 第一列：只能從上面累積
                    grid[i][j] += grid[i - 1][j];
                } else {
                    // 其他位置：選擇上方或左方較小者
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        
        return grid[m - 1][n - 1];
    }
};
