class Solution {
public:
    int bfs(vector<vector<int>>& g, queue<pair<pair<int,int>,int>> q, int r, int c) {
        int time = 0;
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            // Check all 4 directions (up, down, left, right)
            if (i - 1 >= 0 && g[i - 1][j] == 1) { // Up
                g[i - 1][j] = 2;  // Rot the fresh orange
                q.push({{i - 1, j}, t + 1});
            }
            if (i + 1 < r && g[i + 1][j] == 1) { // Down
                g[i + 1][j] = 2;
                q.push({{i + 1, j}, t + 1});
            }
            if (j - 1 >= 0 && g[i][j - 1] == 1) { // Left
                g[i][j - 1] = 2;
                q.push({{i, j - 1}, t + 1});
            }
            if (j + 1 < c && g[i][j + 1] == 1) { // Right
                g[i][j + 1] = 2;
                q.push({{i, j + 1}, t + 1});
            }
            
            time = max(time, t);  // Track the maximum time taken
        }
        return time;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int time = 0;
        int fresh = 0;  // Count fresh oranges initially

        queue<pair<pair<int,int>,int>> q; // {row, col, time}

        // Find all rotten oranges and count fresh ones
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, time});
                } else if (grid[i][j] == 1) {
                    fresh++;  // Count fresh oranges
                }
            }
        }

        // If no fresh oranges, return 0
        if (fresh == 0) return 0;

        // Perform BFS
        time = bfs(grid, q, r, c);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;  // There are still fresh oranges left
                }
            }
        }

        return time;
    }
};
