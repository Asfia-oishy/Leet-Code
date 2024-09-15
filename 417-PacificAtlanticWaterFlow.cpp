class Solution {
public:
    // Modified DFS function with explicit direction handling
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& visited, int i, int j, int r, int c) {
        visited[i][j] = true;

        // Move up
        if (i > 0 && !visited[i - 1][j] && h[i - 1][j] >= h[i][j]) {
            dfs(h, visited, i - 1, j, r, c);
        }
        
        // Move down
        if (i < r - 1 && !visited[i + 1][j] && h[i + 1][j] >= h[i][j]) {
            dfs(h, visited, i + 1, j, r, c);
        }
        
        // Move left
        if (j > 0 && !visited[i][j - 1] && h[i][j - 1] >= h[i][j]) {
            dfs(h, visited, i, j - 1, r, c);
        }
        
        // Move right
        if (j < c - 1 && !visited[i][j + 1] && h[i][j + 1] >= h[i][j]) {
            dfs(h, visited, i, j + 1, r, c);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        // Initialize two boolean matrices to track reachable cells for Pacific and Atlantic
        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));

        // DFS from Pacific ocean (top row and left column)
        for (int i = 0; i < r; ++i) dfs(heights, pacific, i, 0, r, c); // Left column (Pacific)
        for (int j = 0; j < c; ++j) dfs(heights, pacific, 0, j, r, c); // Top row (Pacific)

        // DFS from Atlantic ocean (bottom row and right column)
        for (int i = 0; i < r; ++i) dfs(heights, atlantic, i, c - 1, r, c); // Right column (Atlantic)
        for (int j = 0; j < c; ++j) dfs(heights, atlantic, r - 1, j, r, c); // Bottom row (Atlantic)

        // Find the cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
