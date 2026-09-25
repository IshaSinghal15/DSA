class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    perimeter += 4;

                    for (int d = 0; d < 4; d++) {
                        int ni = i + dr[d];
                        int nj = j + dc[d];

                        if (ni >= 0 && ni < m &&
                            nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            perimeter--;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};