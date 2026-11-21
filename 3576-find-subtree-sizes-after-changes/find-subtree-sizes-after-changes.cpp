
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), newAdj(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1), prev(n, -1);
        vector<int> newParent(n, -1);

        // DFS on original tree
        stack<pair<int, bool>> st;
        st.push({0, false});

        while (!st.empty()) {
            auto [u, exit] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (exit) {
                last[c] = prev[u];
                continue;
            }

            prev[u] = last[c];

            if (last[c] != -1) {
                newParent[u] = last[c];
            } else if (u != 0) {
                newParent[u] = parent[u];
            }

            if (u != 0) {
                newAdj[newParent[u]].push_back(u);
            }

            last[c] = u;

            st.push({u, true});

            for (int i = adj[u].size() - 1; i >= 0; i--) {
                st.push({adj[u][i], false});
            }
        }

        // Calculate subtree sizes in modified tree
        vector<int> sz(n, 1), order;
        stack<int> dfs;
        dfs.push(0);

        while (!dfs.empty()) {
            int u = dfs.top();
            dfs.pop();

            order.push_back(u);

            for (int v : newAdj[u]) {
                dfs.push(v);
            }
        }

        // Reverse traversal: accumulate subtree sizes
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[newParent[u]] += sz[u];
        }

        return sz;
    }
};
