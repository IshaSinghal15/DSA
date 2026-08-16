class Solution {
public:
    vector<int> findMinHeightTrees(
        int n,
        vector<vector<int>>& edges) {

        if (n == 1)
            return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n);

        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        int remaining = n;

        while (remaining > 2) {

            int size = q.size();
            remaining -= size;

            while (size--) {

                int node = q.front();
                q.pop();

                for (int nei : graph[node]) {

                    degree[nei]--;

                    if (degree[nei] == 1)
                        q.push(nei);
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};