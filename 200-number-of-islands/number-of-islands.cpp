class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        int islands = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == '1' && !visited[r][c]) {
                    islands++;

                    queue<pair<int, int>> q;
                    q.push({r, c});
                    visited[r][c] = 1;

                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nr = row + dr[k];
                            int nc = col + dc[k];

                            if (nr >= 0 && nr < rows &&
                                nc >= 0 && nc < cols &&
                                grid[nr][nc] == '1' &&
                                !visited[nr][nc]) {

                                visited[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};