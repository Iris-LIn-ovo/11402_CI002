#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;
        
        for (int num : nums2) {
            // 如果在 set1 中找到該元素，加入 result
            if (set1.count(num)) {
                result.insert(num);
            }
        }
        
        // 將結果轉換回 vector
        return vector<int>(result.begin(), result.end());
    }
};
