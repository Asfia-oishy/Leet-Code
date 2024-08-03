#include <bits/stdc++.h>
using namespace std;


class Solution {
 public:
  int addDigits(int num) {
    int x,sum=0;
    for(int j=0;;j++)
    {
    for(int i=0;; i++)
    {
        x=num%10;
        num=num/10;
        sum+=x;
        if(num==0) break;
    }
    num=sum;
    sum=0;
    if(num/10==0) break;

    }
    return num;
  }
};

int main()
{
    Solution a;

    cout<< a.addDigits(38) << endl;
    return 0;
}