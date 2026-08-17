class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        int ans = 0;
        bool odd = false;

        for (auto [c, count] : freq) {
            ans += (count / 2) * 2;

            if (count % 2)
                odd = true;
        }

        if (odd) ans++;

        return ans;
    }
};