#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        int s_ptr = 0, t_ptr = 0;
        int len = t.size(), cnt = 0;

        while (t_ptr < len)
        {
            if (t[t_ptr] == s[s_ptr])
            {
                cnt++;
                t_ptr++;
                s_ptr++;
            }
            else
            {
                t_ptr++;
            }
        }
        if (cnt == s.size())
            return true;
        return false;
    }
};

int main()
{
    Solution obj;
    cout << boolalpha << obj.isSubsequence("abc", "aghbikc");
    return 0;
}