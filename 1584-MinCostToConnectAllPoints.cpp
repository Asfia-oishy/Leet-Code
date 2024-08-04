#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef pair<ll, pair<ll, ll>> pp_ll; //(cost,(v1,v2))
vector<p_ll> graph[1002];
ll V, E;
priority_queue<pp_ll, vector<pp_ll>, greater<pp_ll>> pq; // min value is on top
vector<vector<ll>> points = { {3,12},{-2,5},{-4,1}};

ll prims(ll src)
{
    while(!pq.empty())
    {
        pq.pop();
    }

    ll n1, n2, edge_count = 0;
    ll  cost;
    bool visited[V+5];
    for (ll j = 0; j < V+5; j++)
    {    visited[j] = false;}
    ll total_cost=0;
    n1 = src;
    visited[src] = true;
    while (edge_count<V-1)
    {

        for (ll i = 0; i < graph[n1].size(); i++)
        {
            n2 = graph[n1][i].second;
            cost = graph[n1][i].first;
            if (visited[n2] == false)
                pq.push(make_pair(cost, make_pair(n1, n2)));
        }

        n1 = pq.top().second.first;
        n2 = pq.top().second.second;
        cost = pq.top().first;
        
        if (visited[n1] && !visited[n2])
        {
            total_cost+=cost;
            visited[n2] = true;
            edge_count++;
        }
        n1 = n2;
        pq.pop();
    }
    return total_cost;
}

void addEdge(ll v1, ll cost, ll v2)
{
    graph[v1].pb(make_pair(cost, v2));
    graph[v2].pb(make_pair(cost, v1));
}

class Solution {
public:
    ll minCostConnectPoints(vector<vector<ll>>& points) {

        
        for(int x=0;x<1002;x++ )
        {
            graph[x].clear();
        }
        V = points.size();
        E= V*(V-1)/2;
        for(ll i=0; i<V-1;i++)
        {
            for(ll j=i+1;j<V;j++)
            {
                ll a1=points[i][0],a2=points[i][1];
                ll b1=points[j][0],b2=points[j][1];

                ll cost = abs(a1-b1)+abs(a2-b2);
                addEdge(i,cost,j); 

            }
        }
        ll ans = prims(0);
        return ans;
        
    }
};


int main()
{
    Solution a;
   
    cout<<a.minCostConnectPoints(points)<<endl;

    return 0;
}