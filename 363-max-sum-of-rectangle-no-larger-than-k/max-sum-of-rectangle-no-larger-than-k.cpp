class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        if (m < n) {
            vector<vector<int>> trans(n, vector<int>(m));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    trans[j][i] = matrix[i][j];
            matrix = trans;
            swap(m, n);
        }
        for (int top = 0; top < m; top++) {
            vector<int> col(n, 0);
            for (int bottom = top; bottom < m; bottom++) {
                for (int j = 0; j < n; j++)
                    col[j] += matrix[bottom][j];
                set<int> prefix;
                prefix.insert(0);
                int sum = 0;
                for (int x : col) {
                    sum += x;
                    auto it = prefix.lower_bound(sum - k);
                    if (it != prefix.end()) ans = max(ans, sum - *it);
                    prefix.insert(sum);
                }
            }
        }

        return ans;
    }
};