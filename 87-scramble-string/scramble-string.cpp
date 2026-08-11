class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string s1, string s2) {
        if (s1 == s2)
            return true;

        string key = s1 + "#" + s2;

        if (memo.count(key))
            return memo[key];

        int n = s1.size();

        // Character frequency pruning
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        for (int x : freq) {
            if (x != 0)
                return memo[key] = false;
        }

        for (int len = 1; len < n; len++) {

            // No swap
            if (solve(
                    s1.substr(0, len),
                    s2.substr(0, len)
                ) &&
                solve(
                    s1.substr(len),
                    s2.substr(len)
                )) {

                return memo[key] = true;
            }

            // Swap
            if (solve(
                    s1.substr(0, len),
                    s2.substr(n - len)
                ) &&
                solve(
                    s1.substr(len),
                    s2.substr(0, n - len)
                )) {

                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;

        return solve(s1, s2);
    }
};