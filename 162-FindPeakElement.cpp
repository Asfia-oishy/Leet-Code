class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //corner cases
        if(n==1) return 0;

        int l = 0;
        int h = nums.size() - 1;
        int ans;

        while (l <= h) 
        {
            int mid = l + (h - l) / 2;
            if(mid==0 && nums[0]>nums[1]) return 0;
            else if(mid == 0)
            {
                l = mid+1;
                continue;

            }

            if(mid == n-1 && nums[mid]>nums[mid-1]) return mid;
            else if(mid == n-1)
            {
                h=mid-1;
                continue;
            }
            
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                ans = mid;
                break;
            }
            else if (nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } 
            else {
                h = mid-1;
            }
        }
        return ans;
    }
};
