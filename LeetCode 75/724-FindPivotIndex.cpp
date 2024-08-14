#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();

        int prefix_sum[n];
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        int sum_left, sum_right;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                sum_left = 0;
            else
                sum_left = prefix_sum[i - 1];
            if (i == n - 1)
                sum_right = 0;
            else
                sum_right = prefix_sum[n - 1] - prefix_sum[i];

            if(sum_left==sum_right)
            return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << s.pivotIndex(nums) << endl;
    return 0;
}