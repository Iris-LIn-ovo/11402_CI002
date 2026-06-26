class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1. n 必須大於 0
        // 2. 3^19 是在 int 範圍內最大的 3 的冪次方，檢查是否能被 n 整除
        return n > 0 && 1162261467 % n == 0;
    }
};
