#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "";
        vector<string> words;
        words.clear();
        int len = s.size();
        if (len == 0 || len == 1)
        {
            return s;
        }
        int l = 0, r = 1;
        bool first_char = false;
        while (l < r)
        {
            if (s[l] == ' ')
            {
                if (r == len)
                    break;

                if (!first_char)
                {
                    l++;
                    r++;
                }
            }
            else
            {
                if (!first_char)
                {
                    first_char = true;
                }
                if (s[r] == ' ' || r == len)
                {
                    string tmp = "";
                    for (int k = l; k < r; k++)
                    {
                        tmp += s[k];
                    }
                    words.push_back(tmp);
                    first_char = false;
                    l = r;
                    if (r < len)
                        r++;
                }
                else // s[r] is a char
                {
                    r++;
                }
            }
        }
        reverse(words.begin(), words.end());
        for (int y = 0; y < words.size(); y++)
        {
            ans += words[y];
            if (y != words.size() - 1)
                ans += ' ';
        }

        return ans;
    }
};
int main()
{

    Solution a;

    cout << a.reverseWords("t ") << endl;
    return 0;
}