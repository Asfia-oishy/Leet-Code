#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {

        int words = dictionary.size();
        int n = s.size();
        map<string, int> mp, mp2;
        for (int i = 0; i < words; i++)
        {
            string word = dictionary[i];
            mp[word]++;
        }
        if (n == 1)
        {
            if (mp.find(s) != mp.end())
                return 0;
            else
                return 1;
        }

        vector<int> check(n, 0);
        map<string, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            string word = it->first;
            // cout<<word<<endl;
            int l = 0, r = 0;
            int curr = 0;
            int end = word.size() - 1;
            bool flag = false;
            while (l < n)
            {
                if (!flag && s[l] == word[0])
                {
                    flag = true;
                    if (end == 0)
                    {
                        if(check[l]==0)
                            check[l] = 1;
                        flag = false;
                        curr = 0;
                    }
                    else
                    {
                        r = l + 1;
                        curr++;
                    }
                }

                if (flag)
                {
                    if (word[curr] == s[r])
                    {
                        if (curr == end)
                        {
                            check[l] = 2;
                            check[r] = 2;
                            curr = 0;
                            l=r+1;
                        }
                        else
                        {
                            r++;
                            curr++;
                        }
                    }
                    else
                    {
                        flag = false;
                        l = r;
                        curr = 0;
                    }
                }
                else
                    l++;
            }
        }

        stack<int> st;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() && check[i] == 0)
            {
                cnt++;
                //cout<<s[i]<<endl;
            }
            else if (check[i] == 2)
            {
                if (st.empty())
                    st.push(2);
                else
                    st.pop();
            }
        }

        return cnt;
    }
};

int main()
{
    Solution s;
    vector<string> dictionary = {"m","its","imaby","pa","ijmnvj","k","mhka","n","y","nc","wq","p","mjqqa","ht","dfoa","yqa","kk","pixq","ixsdln","rh","dwl","dbgnxa","kmpfz","nhxjm","wg","wky","oct","og","uhin","zxb","qz","tpf","hlrc","j","l","tew","xbn","a","uzypt","uvln","mchay","onnbi","hlytk","pjoqlo","dxsjr","u","uj"};
    cout << s.minExtraChar("octncmdbgnxapjoqlofuzypthlytkmchayflwky", dictionary) << endl;
    return 0;
}