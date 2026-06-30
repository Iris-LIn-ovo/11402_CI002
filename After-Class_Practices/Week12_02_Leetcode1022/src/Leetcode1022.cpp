/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        
        // 更新當前的數值
        currentSum = (currentSum << 1) | node->val;
        
        // 若到達葉節點，回傳當前數值
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        // 遞迴計算左右子樹的和
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};
