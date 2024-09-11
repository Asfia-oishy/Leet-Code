//only functional part

bool comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int len = nums.size();

        vector<pair<int, int>> v;
        vector<int> ans;

        for (int i = 0; i < len; i++) {
            v.push_back(make_pair(i, nums[i]));
        }
        sort(v.begin(), v.end(), comp);
        int l = 0, r = len - 1;
        while (l < r) {
            int sum = v[l].second + v[r].second;
            if (sum == target) {
                ans.push_back(v[l].first);
                ans.push_back(v[r].first);
                break;

            } else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
};
