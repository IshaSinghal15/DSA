class Solution {
    vector<int> original;

public:
    Solution(vector<int>& nums) {
        original = nums;
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> ans = original;
        for (int i = ans.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};