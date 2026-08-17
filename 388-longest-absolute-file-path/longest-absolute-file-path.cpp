class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> len;
        len[0] = 0;

        int ans = 0;
        int i = 0;

        while (i < input.size()) {
            int depth = 0;

            while (i < input.size() && input[i] == '\t') {
                depth++;
                i++;
            }

            int start = i;

            while (i < input.size() && input[i] != '\n')
                i++;

            string name = input.substr(start, i - start);

            if (name.find('.') != string::npos) {
                ans = max(ans, len[depth] + (int)name.size());
            } else {
                len[depth + 1] =
                    len[depth] + name.size() + 1;
            }

            if (i < input.size())
                i++;
        }

        return ans;
    }
};