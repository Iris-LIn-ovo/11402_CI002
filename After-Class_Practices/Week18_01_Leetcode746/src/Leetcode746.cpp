#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // dp[i] 代表到達第 i 層樓所需的最小成本
        vector<int> dp(n + 1);
        
        // 初始狀態：到達第 0 層和第 1 層的成本為 0
        dp[0] = 0;
        dp[1] = 0;
        
        for (int i = 2; i <= n; i++) {
            // 狀態轉移：從前一階或前兩階到達當前階的最小成本
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        
        return dp[n];
    }
};
