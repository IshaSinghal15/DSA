class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_set<string> wordSet;

    void dfs(string word, string begin, vector<string>& path) {
        if (word == begin) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string p : parent[word]) {
            path.push_back(p);
            dfs(p, begin, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        wordSet = unordered_set<string>(
            wordList.begin(), wordList.end()
        );

        if (!wordSet.count(endWord))
            return {};

        unordered_set<string> current;
        current.insert(beginWord);

        bool found = false;

        while (!current.empty() && !found) {
            for (string w : current)
                wordSet.erase(w);

            unordered_set<string> next;

            for (string word : current) {
                string temp = word;

                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original)
                            continue;

                        temp[i] = c;

                        if (wordSet.count(temp)) {
                            next.insert(temp);
                            parent[temp].push_back(word);

                            if (temp == endWord)
                                found = true;
                        }
                    }

                    temp[i] = original;
                }
            }

            current = next;
        }

        if (!found)
            return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};