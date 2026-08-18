class NumArray {
    vector<int> bit;
    vector<int> nums;
    int n;

    void updateBIT(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;

        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }

        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        bit.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
            updateBIT(i + 1, nums[i]);
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;

        updateBIT(index + 1, diff);
    }

    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};