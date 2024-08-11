#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {

        int len = candies.size(), maxi = 0;
        vector<bool> result(len);

        for (int i = 0; i < len; i++)
        {
            if (candies[i] > maxi)
                maxi = candies[i];
        }

        for (int i = 0; i < len; i++)
        {
            if (candies[i]+extraCandies >= maxi)
                result[i] = true;
            else
                result[i] = false;
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> candies= {2,3,5,1,3}; 
    bool arr[5]; 
    for(int i=0;i<5;i++)
    {
        arr[i]=a.kidsWithCandies(candies,3)[i];
        cout<<boolalpha<<arr[i]<< " ";
    }
    cout<<endl;
    return 0;
}