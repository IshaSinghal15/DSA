class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> athletes;
        for (int i = 0; i < n; i++) {
            athletes.push_back({score[i], i});
        }

        sort(athletes.begin(), athletes.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        vector<string> ans(n);
        for (int rank = 0; rank < n; rank++) {
            int idx = athletes[rank].second;
            if (rank == 0)
                ans[idx] = "Gold Medal";
            else if (rank == 1)
                ans[idx] = "Silver Medal";
            else if (rank == 2)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(rank + 1);
        }

        return ans;
    }
};