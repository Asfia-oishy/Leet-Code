class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> ans;
        map<vector<int>, int> mp;

        for (int i = 0; i < n - 3 + 1; i++) {
            int a = nums[i];
            int target = a * -1;
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    vector<int> x(3);
                    x[0] = a;
                    x[1] = nums[l];
                    x[2] = nums[r];
                    mp[x]++;
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] < target)
                {
                    l++;
                }
                else
                r--;
            }
        }

        map<vector<int>, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->first);
        }
        return ans;
    }
};