class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int target) {
        if (!root)
            return;

        path.push_back(root->val);

        if (!root->left && !root->right &&
            root->val == target) {

            ans.push_back(path);
        }

        dfs(root->left, target - root->val);
        dfs(root->right, target - root->val);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};