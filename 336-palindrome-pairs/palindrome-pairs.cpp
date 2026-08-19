class Solution {
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            string& w = words[i];
            int len = w.size();
            for (int cut = 0; cut <= len; cut++) {
                if (isPalindrome(w, 0, cut - 1)) {
                    string right = w.substr(cut);
                    if (mp.count(right) && mp[right] != i) {
                        ans.push_back({mp[right], i});
                    }
                }
                if (cut != len &&
                    isPalindrome(w, cut, len - 1)) {
                    string left = w.substr(0, cut);
                    if (mp.count(left) && mp[left] != i) {
                        ans.push_back({i, mp[left]});
                    }
                }
            }
        }

        return ans;
    }
};