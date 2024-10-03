class Solution {
public:

    bool isValid(int mid,vector<int>& nums,int n ,int target)
    {
        int sum =0;
        for(int i =0;i<mid;i++)
        {
            sum += nums[i];
        }
        if(sum>=target)
         return true;

        for(int i =1 ;i<n-mid+1;i++)
        {
            sum -=nums[i-1];
            sum += nums[i+mid-1];

            if(sum>=target) return true;

        }

        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int l = 0;
        int h = n;
        int ans = h;
        bool flag = false;

        while(l<=h)
        {
            int mid = l + (h-l)/2;

            if(isValid(mid,nums,n,target))
            {
                ans = min(ans,mid);
                h = mid-1;
                flag = true;
            }
            else
            {
                l = mid+1;
            }

        }

    if(flag)
        return ans;
    return 0;
        
    }
};