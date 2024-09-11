//only functional part

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        map<string, int> mp;

        for (int i = 0; i < emails.size(); i++) {
            string s = emails[i], ss;
            bool flag = false, f = false;

            for (int j = 0; j < s.size(); j++) {
                if (!f) {
                    if (s[j] == '.')
                        continue;

                    if (s[j] == '+')
                        flag = true;
                    else if (s[j] == '@') {
                        flag = false;
                        f = true;
                    }
                    if (!flag)
                        ss += s[j];

                } else
                    ss += s[j];
            }
            mp[ss]++;
        }
        return mp.size();
    }
};
