#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int arrangeCoins(long long int n)
    {
        long long int l = 1, h = n, mid, ans = 0,val;
        if (n == 1)
            return 1;
        else
        {
            while (l <= h)
            {
                mid = l + (h - l) / 2;
                val = (mid*(mid+1))/2;
                if (val<=n)
                {   ans = max(mid, ans);
                    l=mid+1;
                }
                else
                    h = mid - 1;
            }

            return ans;
        }
    }
};

int main()
{
    Solution a;

    cout << a.arrangeCoins(1804289383) << endl;
    return 0;
}