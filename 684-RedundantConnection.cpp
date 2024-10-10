class Solution {
public:
    void makeset(int val,vector<int> &p)
    {
        p[val] =val;
    }
    int find_p(int val,vector<int> &p)
    {
        if (p[val] == val)
        return val;
    else

        return p[val] = find_p(p[val], p);
    }

    void unite(int x,int y,vector<int> & p)
    {
        int rx = find_p(x,p);
        int ry = find_p(y,p);
        if(rx==ry)
        return;
        else
        p[ry] = rx;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        map <int,int> mp;
        
        int n = edges.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            mp[a]++;
            mp[b]++;

        }
        vector<int> arr;

        map<int,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            arr.push_back(it->first);
        }
        vector<int> p(arr.size()+1);

        for(int i=0;i<arr.size();i++)
            makeset(arr[i],p);
        for(int i=0;i<n;i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            if(find_p(a,p)!=find_p(b,p))
            unite(a,b,p);
            else
            ans.push_back({a,b});

        }

        int m = ans.size();
        return ans[m-1];


    }
};