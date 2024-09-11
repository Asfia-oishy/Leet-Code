#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int len=word1.size() ,len2=word2.size();
        char ans[len+len2];
        string result="";
        if(len<len2)
        {
            int index=-1;
            for(int i=0;i<2*len;i++)
            {
                if(i%2==0)
                    index++;
                if(i%2==0)
                    ans[i]=word1[index];
                else
                    ans[i]=word2[index];
                
            }
            int start=len*2;
            for(int j=len;j<len2;j++)
            {
                ans[start]=word2[j];
                start++;
            }
            for(int i=0;i<len+len2;i++)
            {
                result=result+ans[i];
            }
            return result;
        }
        else
        {   
            int index=-1;
            for(int i=0;i<2*len2;i++)
            {
                if(i%2==0)
                    index++;
                if(i%2==0)
                    ans[i]=word1[index];
                else
                    ans[i]=word2[index];
                
            }
            int start=len2*2;
            for(int j=len2;j<len;j++)
            {
                ans[start]=word1[j];
                start++;
            }
             for(int i=0;i<len+len2;i++)
            {
                result=result+ans[i];
            }
            return result; 
        }

    }
};
int main()
{
    Solution a;
    cout<<a.mergeAlternately("abcd","pq")<<endl;
    return 0;
}
