class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        long long n = spells.size();
        long long m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(),potions.end());

        for(long long i = 0;i<n;i++)
        {

            long long l = 0 ;
            long long h = m-1;
            long long min_ind = -1;

            while(l<=h)
            {
                long long mid = l+(h-l)/2;
                if(spells[i] * (long long)potions[mid]>=success)
                {
                    min_ind = mid;
                    h = mid -1;

                }
                else
                l = mid+1;
            }

            if(min_ind==-1)
                ans[i] = 0;
            else
                ans[i] = (m-min_ind);

        }

        return ans; 
    }
};