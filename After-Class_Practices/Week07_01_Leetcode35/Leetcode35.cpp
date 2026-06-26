#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid; // 找到目標
            } else if (nums[mid] < target) {
                left = mid + 1; // 往右找
            } else {
                right = mid - 1; // 往左找
            }
        }
        
        // 迴圈結束時，left 就是目標應該插入的位置
        return left;
    }
};
