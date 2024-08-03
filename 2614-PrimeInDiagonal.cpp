#include <bits/stdc++.h>
using namespace std;

int isPrime(int n) {
   if(n < 2) return 0;
        for(int i=2;i*i<=n;i++) {
            if(n % i == 0) return 0;
        }
        return n;
}

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int len = nums[0].size(), x , y ,m1=0,max;
        for (int i = 0; i < len; i++) {

            x = isPrime(nums[i][i]);
            y = isPrime(nums[i][len-i-1]);
            max = (x>=y)? x : y;
          //  m1=max;
            if(max>m1) m1=max;
        }
    
        return m1;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> nums ={{1,2,3},{5,6,7},{9,10,11}};

    cout << a.diagonalPrime(nums) << endl;
    return 0;
}