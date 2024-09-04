#include<bits/stdc++.h>
using namespace std;

int visited[202];

bool dfs(vector<vector<char>>& g, int src) {
    stack<int> S;
    bool flag = false;

    S.push(src);
    visited[src] = 1;

    while (!S.empty()) {
        int u = S.top();
        S.pop();
        for (int i = 0; i < g[0].size(); i++) {
            if (g[u][i] == '1') {
                flag =true;
                if (visited[i] != 1) {
                    S.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    return flag;
}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();        
        int nodes=max(m,n),cnt=0;

        for (int i = 0; i <nodes;i++)
            visited[i] = -1;
        bool visit;


        for (int i = 0; i < m; i++) {

            if(visited[i]==-1)
            {
                visit = dfs(grid,i);
                if(visit==true)
                cnt++;
            }

        }

        return cnt;
    }
};

int main()
{
    vector<vector<char>> grid ={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution s;
    cout<<s.numIslands(grid)<<endl;
    return 0;
}