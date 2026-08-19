class Solution {
    vector<int> nums;

public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int ans = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                count++;
                if (rand() % count == 0) ans = i;
            }
        }
        return ans;
    }
};