#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {

        int n = grid[0].size(), cnt = 0;
        vector<int> columns[n];
        map<string, int> r, c;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                columns[j].push_back(grid[i][j]);
            }
        }
        string s = "";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                s += to_string(grid[i][j]);
                s += ',';
            }
            r[s]++;
            s = "";
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                s += to_string(columns[i][j]);
                s += ',';
            }
            c[s]++;
            s = "";
        }
        map<string, int>::iterator it;
        for (it = r.begin(); it != r.end(); it++)
        {
            if (c.find(it->first) != c.end())
            {
                cnt += c[it->first];
                cnt *= it->second;
            }
        }

        return cnt;
    }
};

int main()
{
    vector<vector<int>> grid = {{3, 1, 2, 2}, {1, 4, 4, 4}, {2, 4, 2, 2}, {2, 5, 2, 2}};
    Solution s;
    cout << s.equalPairs(grid) << endl;
    return 0;
}