#include <bits/stdc++.h>
using namespace std;

string gcd(string s1, string s2, string ans) // s1 is greater
{
    int len_ans = ans.size();
    int len1 = s1.size();
    int len2 = s2.size();
    bool f1, f2;

    while (len_ans != 0)
    {
        int cnt = 0;
        f1 = false, f2 = false;
        len_ans = ans.size();
       // cout<<len_ans<<endl;

        if (len1 % len_ans == 0 && len2 % len_ans == 0)
        {
            int val;
            for (int i = 0; i < len1; i++)
            {
                if (i % len_ans == 0)
                    val = 0;
                if (ans[val] == s1[i])
                    cnt++;
                val++;
            }
            if (cnt == len1)
            {
                f1 = true;
            }
            cnt = 0;
            for (int i = 0; i < len2; i++)
            {
                if (i % len_ans == 0)
                    val = 0;
                if (ans[val] == s2[i])
                    cnt++;
                val++;
            }
            if (cnt == len2)
            {
                f2 = true;
            }
        }

        if (f1 && f2)
            return ans;
        else
            ans.pop_back();

        if (ans.size() == 0)
            return ans;
    }
    return ans;
}

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {

        string ans = "";
        int len1 = str1.size(), len2 = str2.size();

        if (len1 < len2)
        {
            ans = ans + str1;
            return gcd(str2, str1, ans);
        }
        else
        {
            ans = ans + str2;
            return gcd(str1, str2, ans);
        }
    }
};

int main()
{
    Solution a;
    cout << a.gcdOfStrings("LEET", "CODE") << endl;
    return 0;
}