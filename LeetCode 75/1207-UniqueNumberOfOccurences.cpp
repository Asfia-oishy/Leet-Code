#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {

        int n = arr.size();
        map<int, int> mp, mp2;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        map<int, int>::iterator it,it2;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            mp2[it->second]++;
        }
        for (it2 = mp2.begin(); it2 != mp2.end(); it2++)
        {
            if (it2->second != 1)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 1, 2, 2, 1, 3};
    cout << boolalpha << s.uniqueOccurrences(arr) << endl;
    return 0;
}