//only functional part


class Solution {

    int dfs(vector<vector<int>>& matrix, int x, int y, int r, int c) {

        if (x < 0 || x >= r || y < 0 || y >= c ||
            matrix[x][y] != 1) // Boundary case for matrix
            return 0;
        int count = 1;

        // Mark current cell as visited
        matrix[x][y] = 0;

        count += dfs(matrix, x + 1, y, r, c); // DOWN
        count += dfs(matrix, x, y + 1, r, c); // RIGHT
        count += dfs(matrix, x - 1, y, r, c); // TOP
        count += dfs(matrix, x, y - 1, r, c); // LEFT
        return count;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int cols = grid[0].size();

        // Iterate for all cells of the array
        int cnt = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    int area_ = dfs(grid, i, j, rows, cols);

                    cnt = max(cnt, area_);
                }
            }
        }
        return cnt;
    }
};
