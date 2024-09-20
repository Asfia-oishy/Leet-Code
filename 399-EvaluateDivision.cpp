class Solution {
public:

    double dfs(string src,string des,map<string,vector<pair<string,double>>>& g,map<string,int>& visited,double product)
    {
        visited[src]++;
        string u = src;
        if(u==des)
            return product;

        
        for(int i = 0;i<g[u].size();i++)
        {
            string v = g[u][i].first;
            double val = g[u][i].second;

            if(visited[v]!=1)
            {
                double ans = dfs(v,des,g,visited,product*val);
                if(ans!=-1.0)
                return ans;

            }

        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        //graph cannot be formed using 2D vector here. beacuse indices are not integer.
        map<string,vector<pair<string,double>>> g;

        int edges = equations.size();
        for(int i=0;i<edges;i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            g[u].push_back({v,w});
            g[v].push_back({u,1.0/w}); //graph created 
        }  

        int q = queries.size();
        vector<double> result(q);
        for(int i = 0; i < q; i++)
        {
            string src = queries[i][0];
            string des = queries[i][1];
            if(g.find(src)==g.end())
             {   result[i]=-1.0;
             continue;}

            map<string,int> visited;

            result[i] = dfs(src,des,g,visited,1.0); //1 is initial product

        }     

        return result;  
    }
};