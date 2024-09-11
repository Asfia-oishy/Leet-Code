#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        int op=0;
        int l=0,r=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(l<r)
        {
            int sum=nums[l]+nums[r];
            if(sum==k)
            {
                op++;
                l++;
                r--;
            }
            else if(sum>k)
            {
                r--;
            }
            else{
                l++;
            }
        }
        return op;
        
    }
};


int main()
{
    Solution obj;
    vector<int> nums={1,2,3,4};
    cout<<obj.maxOperations(nums,5)<<endl;
    return 0;
}