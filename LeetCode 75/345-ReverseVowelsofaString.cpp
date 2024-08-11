#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        string ans;
        int cnt=0;

        for (int i=0;i<s.size();i++)
        {
            int x=s[i];
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
                cnt++;
        }

        
        for (int j=1;j<=cnt/2;j++)
        {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
            {
                
            }
            else
                ans += x;
        }
        return s;
    }
};

int main()
{

    Solution a;

    cout << a.reverseVowels("hello") << endl;
    return 0;
}