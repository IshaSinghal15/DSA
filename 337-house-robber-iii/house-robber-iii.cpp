class Solution {
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        int rob = root->val + left.first + right.first;
        return {notRob, rob};
    }

public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};