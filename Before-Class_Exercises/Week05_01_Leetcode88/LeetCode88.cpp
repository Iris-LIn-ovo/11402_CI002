class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        
        // 當 nums2 還有元素需要合併時
        while (p2 >= 0) {
            // 若 p1 還沒跑完，且 nums1[p1] 較大，則放 nums1[p1]
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--];
            } else {
                // 否則放 nums2[p2]
                nums1[p--] = nums2[p2--];
            }
        }
    }
};
