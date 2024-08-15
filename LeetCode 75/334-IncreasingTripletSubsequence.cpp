#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();

        int small_1 = INT_MAX;
        int small_2 = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= small_1)
            {
                small_1 = nums[i];
            }
            else if (nums[i] <= small_2)
            {
                small_2 = nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 4, 3, 2, 1};
    cout << boolalpha << s.increasingTriplet(nums) << endl;
    return 0;
}