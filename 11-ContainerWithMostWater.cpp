#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    { 
        int len=height.size();
        int l = 0;
        int r = len-1;
        int area = 0;
        
        while (l < r)
        {
            int y = min(height[l], height[r]);
            int x = r - l;
            area = max(area, (x * y));
           if(height[l]<height[r])
           {
            l++;
           }
           else
           {
            r--;
           }

            
        }
        return area;
    }
};

int main()
{
    vector<int> height = {3,2,1,4};
    Solution obj;
    cout << obj.maxArea(height)<<endl;

    return 0;
}