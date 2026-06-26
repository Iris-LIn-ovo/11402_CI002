#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // 使用 long 避免數值為 INT_MIN 時產生錯誤
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (int n : nums) {
            // 如果已存在該數字，跳過以確保「相異」
            if (n == first || n == second || n == third) continue;

            if (n > first) {
                third = second;
                second = first;
                first = n;
            } else if (n > second) {
                third = second;
                second = n;
            } else if (n > third) {
                third = n;
            }
        }

        // 若 third 沒被更新過，代表沒有第三大，回傳最大值
        return (third == LONG_MIN) ? (int)first : (int)third;
    }
};

