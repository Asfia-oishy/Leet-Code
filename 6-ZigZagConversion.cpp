

class Solution {
public:

    string convert(string s, int numRows) {
    
    if(numRows <= 1) return s;

    vector<string>v(numRows, ""); 

    int i = 0;//for s
    int j = 0;//for v
    int counter =0;
    bool flag = true;

    while(i<s.size())
    {
        if(flag)
        {
            v[j]+=s[i];
            i++;
            j++;
             counter++;
            
          
        }
        else
        {
            v[j]+=s[i];
            j--;
            i++;
            counter--;
        }

        if(counter==-1)
        {
            flag = true;
            counter +=2;
            j+=2;
        }
       
        if(counter==numRows)
        {
            flag=false;
            j-=2;
            counter -=2;
        }

    }

    string ans = "";

    for(auto i : v)
     ans+=i;

     return ans;

    }
};
