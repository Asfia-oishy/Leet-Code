#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        bool flag = false;
        int l = 0;
        int h = n - 1, mid;
        int missing = h;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (nums[mid] != mid) {
                missing = min(missing, mid);
                h = mid - 1;
                flag = true;

            }

            else
                l = mid + 1;
        }
        if (!flag)
            return n;
        return missing;
    }
};


int main()
{
    Solution a;
    vector<int> nums ={1,0,3};

    cout << a.missingNumber(nums) << endl;
    return 0;
}