#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<char>> &matrix,int x,int y,int r,int c)
    {
        if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1')  //Boundary case for matrix
            return;
        
        //Mark current cell as visited
        matrix[x][y] = '0';
        
        dfs(matrix,x+1,y,r,c);  //DOWN
        dfs(matrix,x,y+1,r,c);  //RIGHT
        dfs(matrix,x-1,y,r,c);  //TOP
        dfs(matrix,x,y-1,r,c);  //LEFT
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        if(rows==0)  
            return 0;
        int cols = grid[0].size();
        
        //Iterate for all cells of the array
        int cnt = 0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j,rows,cols);
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<char>> grid ={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    Solution s;
    cout<<s.numIslands(grid)<<endl;
    return 0;
}