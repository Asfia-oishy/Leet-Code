#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int l = 1, h = n, mid, ans = n;
        vector<int> arr(n+1);
        for (int j = 0; j <= n; j++)
            arr[j] = 0;

        if (n == 1)
            return 1;
        else
        {
            int i = 1;
            while (n > 0)
            {
                if (n - i >= 0)
                {
                    arr[i] = i;
                    n = n - i;
                }
                else
                {
                    arr[i] = n;
                    n -= i;
                }
                i++;
            }
            while (l <= h)
            {
                mid = l + (h - l) / 2;
                if (arr[mid] != mid)
                {
                    ans = min(mid, ans);
                    h = mid - 1;
                }
                else
                    l = mid + 1;
            }

            return ans - 1;
        }
    }
};

int main()
{
    Solution a;

    cout << a.arrangeCoins(8) << endl;
    return 0;
}