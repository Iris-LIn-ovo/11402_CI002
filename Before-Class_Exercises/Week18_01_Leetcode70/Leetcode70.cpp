class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int prev2 = 1; // f(n-2)
        int prev1 = 2; // f(n-1)
        int current = 0;
        
        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};
