class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        function<void(int)> dfs = [&](int x) {
            if (x > n) return;

            ans.push_back(x);

            for (int i = 0; i <= 9; i++) {
                int next = x * 10 + i;

                if (next > n) break;

                dfs(next);
            }
        };

        for (int i = 1; i <= 9; i++)
            dfs(i);

        return ans;
    }
};