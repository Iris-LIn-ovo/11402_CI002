#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 1. 依照每個區間的起始點進行升序排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // 取得最後一個加入結果的區間（參考點）
            vector<int>& last = merged.back();
            
            // 2. 判斷是否有重疊：當前區間的開始 <= 最後一個區間的結束
            if (intervals[i][0] <= last[1]) {
                // 有重疊，合併：更新結束時間為兩者中較大的一個
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // 無重疊，直接加入
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
