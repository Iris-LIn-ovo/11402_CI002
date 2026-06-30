#include <vector>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // 對於每一個需要檢查的目標數字 i
        for (int i = left; i <= right; ++i) {
            bool covered = false;
            // 檢查它是否被 ranges 中的某個區間覆蓋
            for (const auto& r : ranges) {
                if (i >= r[0] && i <= r[1]) {
                    covered = true;
                    break; // 只要被其中一個區間覆蓋即可
                }
            }
            // 如果該數字沒有被任何區間覆蓋，直接回傳 false
            if (!covered) return false;
        }
        return true;
    }
};
