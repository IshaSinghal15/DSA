class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;
        int len2 = s2.size();
        vector<pair<int, int>> recall(len2, {-1, -1});
        int s1Count = 0;
        int s2Count = 0;
        int pos = 0;
        while (s1Count < n1) {
            for (char c : s1) {
                if (c == s2[pos]) {
                    pos++;
                    if (pos == len2) {
                        pos = 0;
                        s2Count++;
                    }
                }
            }
            s1Count++;
            if (s1Count == n1) break;
            if (recall[pos].first != -1) {
                int prevS1 = recall[pos].first;
                int prevS2 = recall[pos].second;
                int cycleS1 = s1Count - prevS1;
                int cycleS2 = s2Count - prevS2;
                int cycles = (n1 - s1Count) / cycleS1;
                s1Count += cycles * cycleS1;
                s2Count += cycles * cycleS2;
            } else {
                recall[pos] = {s1Count, s2Count};
            }
        }
        return s2Count / n2;
    }
};