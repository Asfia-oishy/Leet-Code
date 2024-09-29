class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) 
                cnt++;
        }

        int l = 0, r = nums.size() - 1;
        while (l < r) {

            if(nums[l]==val)
            {
                if( nums[r]!=val)
                {
                    int tmp = nums[l];
                    nums[l] = nums[r];
                    nums[r] = tmp;
                    l++;
                
                }
                r--;
            }
            else
            {
                l++;
            }
        }
        return cnt;
    }
};