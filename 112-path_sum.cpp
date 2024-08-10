/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
bool visited[50];
int  dis[50],V, E;
vector<int> graph[50], out;
stack<int> S;
void dfs(int src)
{
    visited[src] = true;
    S.push(src);
    dis[src] = 0;
    while(!S.empty())
    {
        int u = S.top();
        out.push_back(u);
        S.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(visited[v]==false)
            {
                visited[v] = true;
                dis[v] = dis[u]+1;
                S.push(v);
            }
        }

    }
}


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        cout<<root<<endl;


        
        
    }
};


int main()
{
    Solution a;


    cout << hasPathSum({5,4,8,11,null,13,4,7,2,null,null,null,1},22) << endl;
    return 0;
}