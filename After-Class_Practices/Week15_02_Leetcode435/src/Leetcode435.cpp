#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // 依照結束時間排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int removeCount = 0;
        int end = intervals[0][1]; // 第一個區間的結束時間
        
        for (size_t i = 1; i < intervals.size(); i++) {
            // 如果下一個區間的開始時間小於當前的結束時間，說明重疊
            if (intervals[i][0] < end) {
                removeCount++; // 移除當前這個區間
            } else {
                // 沒有重疊，更新結束時間
                end = intervals[i][1];
            }
        }
        
        return removeCount;
    }
};
