class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx)
            return 0;

        long long gap =
            (long long)(mx - mn) / (n - 1);

        gap = max(1LL, gap);

        int bucketCount =
            (mx - mn) / gap + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        for (int x : nums) {
            int idx = (x - mn) / gap;

            bucketMin[idx] = min(bucketMin[idx], x);
            bucketMax[idx] = max(bucketMax[idx], x);
            used[idx] = true;
        }

        int ans = 0;
        int prev = mn;

        for (int i = 0; i < bucketCount; i++) {
            if (!used[i])
                continue;

            ans = max(ans, bucketMin[i] - prev);
            prev = bucketMax[i];
        }

        return ans;
    }
};