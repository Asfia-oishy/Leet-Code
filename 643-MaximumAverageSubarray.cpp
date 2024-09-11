#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {

        int sum = 0;
        int max_sum;
        for (int x = 0; x < k; x++)
            sum += nums[x];
        max_sum=sum;
        for(int i=1;i<(nums.size()-k+1);i++)
        {
            sum=sum-nums[i-1]+nums[i+k-1];
            max_sum=max(max_sum,sum);
  
        }
        return double(max_sum)/k;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    cout << s.findMaxAverage(nums, 4) << endl;
    return 0;
}