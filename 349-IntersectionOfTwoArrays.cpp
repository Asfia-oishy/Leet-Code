//only functional part

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        map <int,int> mp;
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums1.erase(unique(nums1.begin(),nums1.end()),nums1.end());
        nums2.erase(unique(nums2.begin(),nums2.end()),nums2.end());

        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(mp.find(nums2[i])!=mp.end())
            {
                ans.push_back(nums2[i]);
            }
        }
        return ans;

    }
};
