#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {

        int n1 = word1.size();
        int n2 = word2.size();
        if (n1 != n2)
            return false;
        map<char, int> mp1, mp2;
        for (int i = 0; i < n1; i++)
        {
            mp1[word1[i]]++;
        }
        for (int i = 0; i < n1; i++)
        {
            mp2[word2[i]]++;
        }
        int occur1 = 0, occur2 = 0;
        vector<int> v1;
        vector<int> v2;
        map<char, int>::iterator it, it2;
        it = mp1.begin();
        for (int i = 0; i < mp1.size(); i++)
        {
            v1.push_back(it->second);
            it++;
        }
        it = mp2.begin();
        for (int i = 0; i < mp2.size(); i++)
        {
            v2.push_back(it->second);
            it++;
        }
        if (v1.size() != v2.size())
            return false;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
                return false;
        }

        for (it = mp1.begin(); it != mp1.end(); it++)
        {
            if (mp2.find((it->first)) == mp2.end())
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << boolalpha << s.closeStrings("cabbba", "abbccc") << endl;
    return 0;
}