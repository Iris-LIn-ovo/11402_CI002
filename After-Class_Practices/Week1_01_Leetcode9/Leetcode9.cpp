class Solution {
public:
    bool isPalindrome(int x) {
        // 負數或以 0 結尾的非零數字都不是回文
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reversedHalf = 0;
        // 反轉後半部分
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        
        // 比較前半部分與反轉後的後半部分
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
