class Solution {
public:
    int m, n;

    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

    void dfs(vector<vector<char>>& board, int r, int c) {
        int mines = 0;
        for (int d = 0; d < 8; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M') {
                mines++;
            }
        }
        if (mines > 0) {
            board[r][c] = '0' + mines;
            return;
        }
        board[r][c] = 'B';
        for (int d = 0; d < 8; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'E') {
                dfs(board, nr, nc);
            }
        }
    }
    vector<vector<char>> updateBoard(
        vector<vector<char>>& board,
        vector<int>& click) {
        m = board.size();
        n = board[0].size();
        int r = click[0];
        int c = click[1];
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        dfs(board, r, c);
        return board;
    }
};