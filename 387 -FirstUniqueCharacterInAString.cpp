//only functional part

class Solution {
public:
    int firstUniqChar(string s) {

        map<char,int> mp;
        queue<int> q;
        string str;

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            q.push(s[i]);
        }
        map<char,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==1)
            {
                str+=it->first;

            }
        }
        int index;
        if(str.size()==0)
        return -1;

        for(int i=0;i<s.size();i++)
        {
            int x = q.front();
            if(str.find(x)!=string::npos)
            {
                index=i;
                break;

            }
            q.pop();
        }

        return index;

    }
};
