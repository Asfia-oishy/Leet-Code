class Solution {
public:

    int dfs(vector<vector<int>>& g,int i,int j,int r,int c)
    {
        if(i<0 || i>=r || j<0 || j >=c || g[i][j]==0)
        return 0;

        int gold = g[i][j];
        g[i][j] = 0;

        int gold1 = dfs(g,i+1,j,r,c);
        int gold2 = dfs(g,i-1,j,r,c);
        int gold3 = dfs(g,i,j+1,r,c);
        int gold4 = dfs(g,i,j-1,r,c);

        g[i][j] = gold;

        return gold + max({gold1,gold2,gold3,gold4});
    }
    int getMaximumGold(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        int max_gold = 0;

        for(int i =0; i < r ;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]!=0)
                {
                    max_gold = max(max_gold, dfs(grid,i,j,r,c));


                }
            }
        }
        return max_gold;
        
    }
};