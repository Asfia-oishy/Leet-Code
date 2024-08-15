#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int len = nums.size();
        int p[len], s[len]; // prefix,suffix

        for (int i = 0; i < len; i++)
        {
            if (i == 0)
                p[i] = nums[i];
            else
                p[i] = p[i - 1] * nums[i];
        }
        for (int i = len - 1; i >= 0; i--)
        {
            if (i == len - 1)
                s[i] = nums[i];
            else
                s[i] = nums[i] * s[i + 1];
        }
        vector<int> ans;
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
                ans.push_back(s[i + 1]);
            else if (i == len - 1)
                ans.push_back(p[i - 1]);
            else
                ans.push_back(p[i - 1] * s[i + 1]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = s.productExceptSelf(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i] << endl;
        else
            cout << ans[i] << " ";
    }

    return 0;
}