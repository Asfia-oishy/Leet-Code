//only functional part



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        // Edge case: if any of the input vectors are empty or k is 0, return an empty result
        if (nums1.empty() || nums2.empty() || k == 0) {
            return ans;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Initialize the heap with pairs: (nums1[i] + nums2[0], i, 0) for all i
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }


        while (k-- > 0 && !pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int i = current.second.first;   // index in nums1
            int j = current.second.second;  // index in nums2


            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};
