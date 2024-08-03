#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, h = num / 2, mid, result = -1;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if ((num % mid == 0) && ((num / mid) == mid)) {
                result = mid;
                break;
            }
            if (num / mid < mid)
                h = mid - 1;
            else
                l = mid + 1;
        }
        if (result != -1 || num==1)
            return true;
        else
            return false;
    }
};


int main()
{
    Solution a;

    cout <<boolalpha<< a.isPerfectSquare(4) << endl;
    return 0;
}