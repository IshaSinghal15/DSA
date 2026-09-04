class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict;
        for (string& word : words) dict.insert(word);
        vector<string> ans;
        for (string& word : words) {
            int n = word.size();
            if (n == 0) continue;
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (!dp[j]) continue;
                    string part = word.substr(j, i - j);
                    if (j == 0 && i == n) continue;
                    if (dict.count(part)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[n]) ans.push_back(word);
        }
        return ans;
    }
};