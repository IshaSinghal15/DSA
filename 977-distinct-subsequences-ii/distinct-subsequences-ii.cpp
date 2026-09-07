class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(26, 0);
        long long total = 1; // empty subsequence

        for (char ch : s) {
            int c = ch - 'a';

            long long newTotal = (2 * total - dp[c] + MOD) % MOD;

            dp[c] = total;
            total = newTotal;
        }

        return (total - 1 + MOD) % MOD;
    }
};