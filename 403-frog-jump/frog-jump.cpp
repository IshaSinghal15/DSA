class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp;
        for (int x : stones) dp[x] = {};
        dp[0].insert(0);
        for (int x : stones) {
            for (int jump : dp[x]) {
                for (int d = jump - 1; d <= jump + 1; d++) {
                    if (d <= 0) continue;
                    int next = x + d;
                    if (next == stones.back()) return true;
                    if (dp.count(next)) dp[next].insert(d);
                }
            }
        }
        return stones.size() == 1;
    }
};