//only functional part

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp; // To store the cumulative sum frequencies
        int sum = 0, count = 0;

        // Initialize with sum 0 occurring once to handle cases where a subarray
        // itself equals k
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int val = sum - k;

            // Check if (sum - k) exists in the map, indicating a valid subarray
            if (mp.find(val) != mp.end()) {
                count += mp[val];
            }

            // Add the current cumulative sum to the map
            mp[sum]++;
        }

        return count;
    }
};
