class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // 若回傳值不為 -1，代表整棵樹是平衡的
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        
        // 檢查左子樹
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;
        
        // 檢查右子樹
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;
        
        // 檢查當前節點是否平衡
        if (abs(leftHeight - rightHeight) > 1) return -1;
        
        // 回傳當前高度
        return max(leftHeight, rightHeight) + 1;
    }
};
