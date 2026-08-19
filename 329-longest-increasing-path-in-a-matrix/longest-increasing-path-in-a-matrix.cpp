class Solution {
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (dp[r][c]) return dp[r][c];
        dp[r][c] = 1;
        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
                dp[r][c] = max(dp[r][c], 1 + dfs(matrix, nr, nc));
            }
        }
        return dp[r][c];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(matrix, i, j));
        return ans;
    }
};