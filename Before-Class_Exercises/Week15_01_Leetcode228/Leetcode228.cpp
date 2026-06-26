#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            
            // 往後尋找連續的數字
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            
            // 判斷並格式化區間
            if (start != nums[i]) {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            } else {
                result.push_back(to_string(start));
            }
        }
        
        return result;
    }
};
