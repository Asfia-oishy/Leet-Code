//only functional part

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        map<int,int> ::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> val;
        for(int i=1;i<=k;i++)
        {
            val.push_back(pq.top().second);
            pq.pop();
        }
        return val;
    }
};
