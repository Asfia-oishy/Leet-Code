class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) return true; // All characters are matched

        int r = board.size();
        int c = board[0].size();

        // Boundary conditions and if the current cell doesn't match or is visited
        if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] != word[index] || visited[i][j]) {
            return false;
        }

        // Mark the current cell as visited
        visited[i][j] = true;

        // Explore all 4 possible directions: up, down, left, right
        bool found = dfs(board, word, i - 1, j, index + 1, visited) ||
                     dfs(board, word, i + 1, j, index + 1, visited) ||
                     dfs(board, word, i, j - 1, index + 1, visited) ||
                     dfs(board, word, i, j + 1, index + 1, visited);

        // Backtrack by unmarking the current cell as visited
        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false)); // To track visited cells

        // Try to find the word starting from each cell
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }

        return false; // Word not found
    }
};
