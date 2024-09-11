#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        int n = asteroids.size();
        vector<int> ans;
        st.push(asteroids[0]);
        for (int i = 1; i < n; i++)
        {
            int val = asteroids[i];
            if (!st.empty() && (st.top() > 0 && val < 0))
            {
                while ((st.top() > 0 && val < 0))
                {
                    if (abs(st.top()) == abs(val))
                    {
                        st.pop();
                        break;
                    }
                    else if (abs(st.top()) < abs(val))
                    {
                        st.pop();
                        if (!st.empty())
                        {
                            if (st.top() < 0)
                            {
                                st.push(val);
                            }
                        }
                        else
                        {
                            st.push(val);
                        }
                    }
                    else if (abs(st.top()) > abs(val))
                        break;
                }
            }
            else
                st.push(val);
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> as = {1,-1,-2,-2}, ans;
    ans = s.asteroidCollision(as);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}