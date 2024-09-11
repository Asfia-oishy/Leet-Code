#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {

        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            st.push(s[i]);

            if (st.top() == '*')
            {
                st.pop();
                if (!st.empty())
                    st.pop();
            }
        }
        string ans;
        int nn = st.size();
        for (int i = 0; i < nn; i++)
        {
            int x = st.top();
            ans += x;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.removeStars("leet**cod*e") << endl;
    return 0;
}