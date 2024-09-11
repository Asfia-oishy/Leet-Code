#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            if (nums[r] == 0)
            {
                r--;
                continue;
            }

            if (nums[l] == 0)
            {
                while (l < r)
                {
                    int tmp = nums[l];
                    nums[l] = nums[l + 1];
                    nums[l + 1] = tmp;
                    l++;
                }

                r--;
                l = 0;
            }
            else
            {
                l++;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
    }
};
int main()
{
    vector<int> nums = {0,0, 1};
    Solution obj;
    obj.moveZeroes(nums);
    return 0;
}