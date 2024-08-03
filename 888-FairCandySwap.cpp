#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        int sum_a =0, sum_b=0 ;
        vector<int> ans(2);
        for(int x : aliceSizes)
        {
            sum_a+=x;
        }
        for(int y : bobSizes)
        {
            sum_b+=y;
        }
        int diff;

        for (int i = 0; i < aliceSizes.size(); i++)
        {
            for (int j = 0; j < bobSizes.size(); j++)
            {
                diff = aliceSizes[i]-bobSizes[j];
                if(sum_a-diff==sum_b+diff)
                {
                    ans[0]=aliceSizes[i];
                    ans[1]=bobSizes[j];
                    break;
                }

            }

            
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> a_ = {1, 2,5};
    vector<int> b_ = {2, 4};

    vector<int> ans = a.fairCandySwap(a_, b_);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}