class Solution {
public:
    int romanToInt(string s) {

        map<char,int> mp;
        vector<char> roman = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> integer = {1, 5, 10, 50, 100, 500, 1000};
        
        int ind = 0;
        for(auto i : roman)
        {
            mp[i]=integer[ind];
            ind++;
        }
       
        int result = 0,val;
        int n =s.size();
        vector<int> check(n,0);
        for(int i = 0;i<n-1;i++)
        {
            int x = mp[s[i]];
            int y = mp[s[i+1]];

            if(check[i]==1)
                continue;

            if(x<y)
            {
                result += (y-x);
                check[i] = 1;
                check[i+1] = 1;
            }
            else
            {
                result += x ;
                check[i] = 1;
            }
       
        }

        if(check[n-1]==0)
            result+=mp[s[n-1]];

    return result;
    }
};