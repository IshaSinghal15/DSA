class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<int> row(26);

        for (int i = 0; i < 3; i++) {
            for (char c : rows[i]) {
                row[c - 'a'] = i;
            }
        }

        vector<string> ans;

        for (string& word : words) {
            int r = row[tolower(word[0]) - 'a'];
            bool ok = true;

            for (char c : word) {
                if (row[tolower(c) - 'a'] != r) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans.push_back(word);
        }

        return ans;
    }
};