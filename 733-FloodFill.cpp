class Solution {
public:
    void dfs(vector<vector<int>>& img, int i, int j, int m, int n, int clr,
             int org_clr) {
        if (i < 0 || i >= m || j < 0 || j >= n || img[i][j] != org_clr)
            return;

        img[i][j] = clr;

        dfs(img, i - 1, j, m, n, clr, org_clr);
        dfs(img, i + 1, j, m, n, clr, org_clr);
        dfs(img, i, j - 1, m, n, clr, org_clr);
        dfs(img, i, j + 1, m, n, clr, org_clr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];

        if (originalColor != color) {
            dfs(image, sr, sc, m, n, color, originalColor);
        }

        return image;
    }
};