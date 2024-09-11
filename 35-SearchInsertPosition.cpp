//only functional part


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l = 0, n = nums.size(), h = n - 1;
        int ans;

        if (target < nums[0])
            return 0;
        else if (target > nums[n - 1])
            return n;

        else {
            for (int i = 0; i < n; i++) {
                if (nums[i] == target) {
                    ans = i;
                    break;
                } else if (target > nums[i] && target < nums[i + 1]) {
                    ans = i + 1;
                    break;
                }
            }
        }
        return ans;
    }
};
