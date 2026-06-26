class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 右側和 = 總和 - 左側和 - 目前元素本身
            int rightSum = totalSum - leftSum - nums[i];
            
            if (leftSum == rightSum) {
                return i;
            }
            
            // 更新左側和，準備進入下一個索引
            leftSum += nums[i];
        }
        
        return -1;
    }
};
