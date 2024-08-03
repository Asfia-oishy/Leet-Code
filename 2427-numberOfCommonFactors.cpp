#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int commonFactors(int a, int b) {

        int factors=0;
        int min=a<b?a:b;
        while(1)
        {
            if(a%min==0 && b%min==0)
            {
                factors++;
            }
            min--;
            if(min==0) break;

        }
        return factors;
        
    }
};


int main()
{
    Solution a;

    cout << a.commonFactors(12,6) << endl;
    return 0;
}