class Solution {
public:
    vector<int> dfs(vector<vector<int>>& land, int i, int j, int r, int c) {
     
        if (i < 0 || i >= r || j < 0 || j >= c || land[i][j] == 0) {
            return {1000, 1000, 0, 0};  
        }

        land[i][j] = 0;
        

        int r1 = i, c1 = j, r2 = i, c2 = j;


        vector<int> down = dfs(land, i + 1, j, r, c);
        vector<int> up = dfs(land, i - 1, j, r, c);
        vector<int> left = dfs(land, i, j - 1, r, c);
        vector<int> right = dfs(land, i, j + 1, r, c);

     
        r1 = min({r1, down[0], up[0], left[0], right[0]});
        c1 = min({c1, down[1], up[1], left[1], right[1]});
        r2 = max({r2, down[2], up[2], left[2], right[2]});
        c2 = max({c2, down[3], up[3], left[3], right[3]});

        return {r1, c1, r2, c2};  
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int r = land.size();
        int c = land[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
           
                if (land[i][j] == 1) {
                    vector<int> farm = dfs(land, i, j, r, c);
                    ans.push_back(farm);
                }
            }
        }

        return ans;
    }
};
