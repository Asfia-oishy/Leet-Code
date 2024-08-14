#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int altitude=0;
        int max_altitude=0;
        for(int i=0;i<gain.size();i++)
        {
            altitude = altitude+gain[i];
            max_altitude=max(max_altitude,altitude);
            
        }
        return max_altitude;
        
    }
};

int main()
{
    Solution obj;
    vector<int> gain={44,32,-9,52,23,-50,50,33,-84,47,-14,84,36,-62,37,81,-36,-85,-39,67,-63,64,-47,95,91,-40,65,67,92,-28,97,100,81};
    cout<<obj.largestAltitude(gain)<<endl;
    return 0;
}