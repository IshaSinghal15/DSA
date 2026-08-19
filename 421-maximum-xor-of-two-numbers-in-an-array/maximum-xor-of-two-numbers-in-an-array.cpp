class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int mask = 0;
        for (int bit = 30; bit >= 0; bit--) {
            mask |= (1 << bit);
            unordered_set<int> prefixes;
            for (int x : nums) prefixes.insert(x & mask);
            int candidate = ans | (1 << bit);
            for (int p : prefixes) {
                if (prefixes.count(p ^ candidate)) {
                    ans = candidate;
                    break;
                }
            }
        }

        return ans;
    }
};