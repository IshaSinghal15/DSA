class Solution {
    unordered_map<string, multiset<string>> graph;
    vector<string> ans;

    void dfs(string airport) {
        while (!graph[airport].empty()) {
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(next);
        }

        ans.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets)
            graph[ticket[0]].insert(ticket[1]);

        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};