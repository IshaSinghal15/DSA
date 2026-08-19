class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        function<int(int,int)> solve = [&](int l, int r) {
            if (r - l < k) return 0;
            int cnt[26] = {};
            for (int i = l; i < r; i++) cnt[s[i] - 'a']++;
            for (int i = l; i < r; i++) {
                if (cnt[s[i] - 'a'] < k) {
                    int j = i + 1;
                    while (j < r && cnt[s[j] - 'a'] < k) j++;
                    return max(solve(l, i), solve(j, r));
                }
            }
            return r - l;
        };

        return solve(0, n);
    }
};