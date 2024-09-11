//only functional part

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string,vector<string>> mp;
        vector<vector<string>> ans;
        int n = strs.size();
        for(int i=0;i<n;i++)
        {
            string s = strs[i],s_copy=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(s_copy);
        }

        map <string,vector<string>>:: iterator it;

        for(it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);

        }

        return ans;

    }
};
