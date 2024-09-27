class Solution {
public:
    string intToRoman(int num) {

        map<int,string> mp;
        vector<string> roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector<int> integer = {1,4, 5,9 ,10,40, 50,90, 100,400, 500,900, 1000};
        int n = roman.size();
        
        int ind = 0;
        for(auto i : integer)
        {
            mp[i]=roman[ind];
            ind++;
        }

        vector<pair<string,int>> ans; 
        string s = "";

        int md;
        while(num)
        {
            for(int i = n-1; i >= 0; i-- )
            {
                int val = num/integer[i];
                if(val == 0) continue;
          
                ans.push_back({mp[integer[i]],val});
                num = num%integer[i];
                break;
            }
        }

        for(int i = 0;i<ans.size();i++)
        {
            int val = ans[i].second;
            while(val--)
            {
                s+=ans[i].first;
            }
        }


        return s;

        
        
    }
};