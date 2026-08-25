class Solution {
public:
    vector<int> ans;
    int prev = 0;
    int currCount = 0;
    int maxCount = 0;
    bool first = true;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (first || root->val != prev) {
            currCount = 1;
            first = false;
        } else {
            currCount++;
        }
        if (currCount > maxCount) {
            maxCount = currCount;
            ans.clear();
            ans.push_back(root->val);
        } else if (currCount == maxCount) {
            ans.push_back(root->val);
        }
        prev = root->val;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};