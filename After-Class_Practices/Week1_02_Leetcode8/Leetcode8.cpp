#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        // 1. 跳過前導空格
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;
        
        // 2. 判斷正負號
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // 3. 讀取並轉換數字
        long long res = 0; // 使用 long long 防止計算過程溢位
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            
            // 4. 溢位處理
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return (int)(res * sign);
    }
};
