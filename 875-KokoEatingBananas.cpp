class Solution {
public:
    bool isPossible(int mid,vector<int>& p,int h)
    {
        long long total = 0;
        for(int i = 0;i<p.size();i++)
        {
            int time = ceil(p[i]*1.0/mid);
            total+=time;
        }

        if(total<=h)
            return true;
        return false;

    }
    int minEatingSpeed(vector<int>& piles, int h) {

    
        int n = piles.size();
        int mx = 0;
        for(int i =0;i<n;i++)
        {
            if(piles[i]>mx)
                mx=piles[i];

        }
        int l = 1;
        int r = mx;
        int ans;

        while(l<=r)
        {
            int mid = (r+l)/2;

            if(isPossible(mid,piles,h))
            {
                ans = mid;
                r = mid-1;
            }
            else
                l=mid+1;

        }
        return ans;
        
    }
};