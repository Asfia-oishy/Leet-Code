#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {

        int n = chars.size();
        string s = "";
        if (n == 1)
        {
            s += chars[0];
            chars.clear();
            chars.push_back(s[0]);
            return chars.size();
        }
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            cnt++;

            if (i < n - 1)
            {
                if (chars[i] != chars[i + 1])
                {
                    if (cnt == 1)
                    {
                        s += chars[i];
                        cnt = 0;
                    }
                    else
                    {
                        s += chars[i];
                        s += to_string(cnt);
                        cnt = 0;
                    }
                }
            }

            else
            {
                if (chars[i] != chars[i - 1])
                {
                    s += chars[i];
                    cnt = 0;
                }
                else
                {
                    s += chars[i];
                    s += to_string(cnt);
                    cnt = 0;
                }
            }

        }
        chars.clear();
        for (int i = 0; i < s.size(); i++)
        {
            chars.push_back(s[i]);
        }

        return chars.size();
    }
};

int main()
{
    Solution s;
    vector<char> ch = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    cout << s.compress(ch) << endl;
    return 0;
}