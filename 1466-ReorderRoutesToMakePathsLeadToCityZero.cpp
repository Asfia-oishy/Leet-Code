class Solution {
public:
    int reorder_routes(vector<vector<pair<int, int>>>& g, vector<int>& fixed)
    {
        int cnt = 0;
        fixed[0]=1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i].first;
                int val = g[u][i].second;
                if(fixed[v]==0)
                {
                    if(val==1)
                    {
                        cnt++;
                    }
                    q.push(v);
                    fixed[v]=1;
                }
                
            }
        }
        return cnt;
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        int edges = connections.size();
        vector<vector<pair<int, int>>> g(n); // pair is for real and img edge detection
        for (int i = 0; i < edges; i++) 
        {
            int u = connections[i][0];
            int v = connections[i][1];
            g[u].push_back({v, 1}); // real edge;
            g[v].push_back({u, 0}); // fake edge;
        }
        vector<int> fixed(n, 0); // to check if the node is reordered

        int cnt = reorder_routes(g, fixed);

        return cnt;
    }
};