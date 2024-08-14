#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        map<int, int> mp1;
        map<int, int> mp2;
        for (int i = 0; i < n1; i++)
        {
            mp1[nums1[i]]++;
        }
        for (int i = 0; i < n2; i++)
        {
            mp2[nums2[i]]++;
        }
        vector<vector<int>> ans(2);
        ans[0].clear();
        ans[1].clear();
 
        for (int i = 0; i < n1; i++)
        {
            if (mp2[nums1[i]]==0)
            {
                ans[0].push_back(nums1[i]);
                mp2[nums1[i]]++;
             
            }
        }
    
        for (int i = 0; i < n2; i++)
        {
            if (mp1[nums2[i]] ==0)
            {
                ans[1].push_back(nums2[i]);
                mp1[nums2[i]]++;
              
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {-73}, nums2 = {-66,9,-54,-32,94,11};
    vector<vector<int>> ans = s.findDifference(nums1, nums2);

    for (int i = 0; i < ans[0].size(); i++)
        cout << ans[0][i] << " ";
    cout<<endl;
    for (int i = 0; i < ans[1].size(); i++)
        cout << ans[1][i] << " ";
    cout<<endl;
    return 0;
}
  