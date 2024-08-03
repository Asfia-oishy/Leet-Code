#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0) return n;
        else
        {
            return n*2;
        }
        
    }
};


int main()
{
    Solution a;

    cout << a.smallestEvenMultiple(5) << endl;
    return 0;
}