class Solution {
public:

    bool dfs(int src,vector<vector<int>>& g,vector<int> &vis)
    {
        vis[src]=1;

        for(int i=0;i<g[src].size();i++)
        {
            int v=g[src][i];
            if(vis[v]==0)
            {
                if(dfs(v,g,vis))
                 return true;
            }
            if(vis[v]==1)
            return true;
        }
        vis[src]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int nodes = numCourses;
        vector<vector<int>> g(nodes);

        for(int i=0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            g[u].push_back(v);
        }

        vector<int> visited(nodes,0);
        bool cycle = false;

        for(int i=0;i<nodes;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,g,visited))
                cycle = true;
            }
        }

        return !cycle; 
    }
};
