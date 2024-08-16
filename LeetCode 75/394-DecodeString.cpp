#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {

        int n = s.size(), k;
        stack<char> st;
        bool flag = false;
        string ans = "",a;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[')
                continue;
            if (s[i] == ']')
            {
                a="";
                while (!st.empty())
                {
                    a += st.top();
                    st.pop();
                }
                reverse(a.begin(), a.end());
                while (k--)
                    ans += a;
            }

            else if (s[i] >= 48 && s[i] <= 57)
            {
                k = int(s[i] - '0');
            }
            else
            {
                st.push(s[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    return 0;
}