class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        for (int d = 0; d < m + n - 1; d++) {
            vector<int> diagonal;
            int r, c;
            if (d < n) r = 0, c = d;
            else r = d - n + 1, c = n - 1;
            while (r < m && c >= 0) {
                diagonal.push_back(mat[r][c]);
                r++;
                c--;
            }
            if (d % 2 == 0) reverse(diagonal.begin(), diagonal.end());
            for (int x : diagonal) ans.push_back(x);
        }
        return ans;
    }
};