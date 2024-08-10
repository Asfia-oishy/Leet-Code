#include <bits/stdc++.h>
using namespace std;

#define HIGH 9999999
typedef long long int ll;
typedef pair<ll, ll> t_pair;

void add_edge(vector<t_pair> g[], ll u, ll v, ll cost)
{
    g[u].push_back(make_pair(cost, v));
}

ll Dijkstra(vector<t_pair> g[], vector<ll> &dist, ll src, ll n)
{
    priority_queue<t_pair, vector<t_pair>, greater<t_pair>> pq;
    dist[src] = 0;
    pq.push(make_pair(dist[src], src));
    while (!pq.empty())
    {
        ll u1 = pq.top().second;
        pq.pop();
        for (ll i = 0; i < g[u1].size(); i++)
        {
            ll v1 = g[u1][i].second;
            ll weight = g[u1][i].first;

            if (dist[v1] > dist[u1] + weight)
            {
                dist[v1] = dist[u1] + weight;
                pq.push(make_pair(dist[v1], v1));
            }
        }
    }
    ll delay = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (dist[i] == HIGH)
        {
            return -1;
        }
        if (dist[i] > delay)
            delay = dist[i];
    }
    return delay;
}

class Solution
{
public:
    ll networkDelayTime(vector<vector<int>> &times, ll n, ll k)
    {
        vector<t_pair> g[101]; 
        vector<ll> dist(n + 1, HIGH); 

        for (ll i = 0; i < times.size(); i++)
        {
            ll u = times[i][0];
            ll v = times[i][1];
            ll w = times[i][2];
            add_edge(g, u, v, w);
        }

        ll delay = Dijkstra(g, dist, k, n);
        return delay;
    }
};

int main()
{
    vector<vector<int>> points = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    Solution a;

    cout << a.networkDelayTime(points, 4, 2) << endl;

    return 0;
}
