class Solution {
public:
    unordered_map<int, int> freq;
    int maxFreq = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = left + right + root->val;
        freq[sum]++;
        maxFreq = max(maxFreq, freq[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        freq.clear();
        maxFreq = 0;
        dfs(root);
        vector<int> ans;
        for (auto &[sum, count] : freq) {
            if (count == maxFreq) ans.push_back(sum);
        }
        return ans;
    }
};