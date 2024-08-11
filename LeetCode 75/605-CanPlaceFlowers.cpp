#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int len = flowerbed.size();
        int avail = 0;
        vector<int> index_1;
        if (n == 0)
            return true;
        else if (len == 1)
        {
            if (flowerbed[0] == 0 && n == 1)
                return true;
            else
                return false;
        }
        for (int i = 0; i < len; i++)
        {
            if (flowerbed[i] == 0)
            {
                if (i == 0)
                {
                    if (flowerbed[i + 1] == 0)
                    {
                        avail++;
                        flowerbed[i] = 1;
                    }
                }
                else if(i==len-1)
                {
                    if(flowerbed[i-1]==0)
                    {
                        avail++;
                        flowerbed[i]=1;
                    }
                }

                else
                {
                    if (flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0)
                    {
                        avail++;
                        flowerbed[i] = 1;
                    }
                }
            }
        }

        if (avail >= n)
            return true;
        return false;
    }
};

int main()
{

    Solution a;
    vector<int> flowerbed = {1, 0};
    int n = 1;
    cout << boolalpha << a.canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}