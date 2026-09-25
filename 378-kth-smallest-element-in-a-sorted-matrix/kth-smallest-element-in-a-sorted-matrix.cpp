class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // {value, row, column}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // First element of each row
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        // Remove the smallest k-1 elements
        for (int count = 1; count < k; count++) {
            auto [value, row, col] = pq.top();
            pq.pop();

            // Add next element from the same row
            if (col + 1 < n) {
                pq.push({matrix[row][col + 1], row, col + 1});
            }
        }

        return get<0>(pq.top());
    }
};