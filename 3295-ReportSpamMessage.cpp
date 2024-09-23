class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {

        map<string,int> mp;
        int cnt = 0;

        for(int i=0;i<bannedWords.size();i++)
        {
            mp[bannedWords[i]]++;
        }

        for(int i=0;i<message.size();i++)
        {
            if(mp.find(message[i])!=mp.end())
                cnt++;
            if(cnt==2)
            {
                return true;
            }

        }
        return false;
        
    }
};