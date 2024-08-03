#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isThree(int n)
    {
        int c = 0;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                c++;
        }
        if (c == 1)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution a;

    cout <<boolalpha<< a.isThree(4) << endl;
    return 0;
}