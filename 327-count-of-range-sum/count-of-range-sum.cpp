class Solution {
    long long mergeSort(vector<long long>& a, int l, int r, long long lower, long long upper) {
        if (r - l <= 1) return 0;
        int m = l + (r - l) / 2;
        long long ans = mergeSort(a, l, m, lower, upper) + mergeSort(a, m, r, lower, upper);
        int j = m, k = m;
        for (int i = l; i < m; ++i) {
            while (j < r && a[j] - a[i] < lower) j++;
            while (k < r && a[k] - a[i] <= upper) k++;
            ans += k - j;
        }
        inplace_merge(a.begin() + l, a.begin() + m, a.begin() + r);
        return ans;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) prefix[i + 1] = prefix[i] + nums[i];
        return (int)mergeSort(prefix, 0, prefix.size(), lower, upper);
    }
};