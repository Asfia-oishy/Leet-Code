#include <bits/stdc++.h>
using namespace std;

bool checked(vector<int> nums, int k)
{
    int cnt = 0;

    for (int i = 0; i < k; i++) // 1st window
    {
        if (nums[i] == 0)
            cnt++;
    }
    if (cnt == 1 || cnt==0)
        return true;
    for (int i = 1; i < nums.size() - k + 1; i++)
    {
        if (nums[i - 1] == 0)
            cnt--;
        if (nums[i + k - 1] == 0)
            cnt++;
        if (cnt == 1 || cnt==0)
            return true;
    }
    return false;
}

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {

        int low = 0, high = nums.size()-1; // window size
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (checked(nums, mid + 1))
            {
                low = mid + 1;
                ans = max(ans, mid);
                //cout<<ans<<endl;
            }

            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> nums = {1,1,0,1};
    cout << a.longestSubarray(nums) << endl;

    return 0;
}