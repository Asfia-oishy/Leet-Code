#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        string vowels = "AEIOUaeiou";
        int l = 0;
        int r = s.size() - 1;
        bool f1,f2;
        while (l < r)
        {
            f1=false;
            f2=false;

            for (char x : vowels)
            {
                if (x == s[l])
                    f1 = true;
            }
            if(!f1)
            {
                l++;
            }
            for (char x : vowels)
            {
                if (x==s[r])
                    f2 = true;
            }
            if(!f2)
            {
                r--;
            }
            if(f1 && f2)
            {
                char temp = s[l];
                s[l]=s[r];
                s[r]=temp;
                l++;
                r--;
            }
          
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