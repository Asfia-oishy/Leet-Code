#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    int result;
    result = (a < b) ? a : b;
    for (int i = 0;; i++) {
        if (a % result == 0 && b % result == 0)
            return result;
        else
            result--;
    }
}
int find_fdgt(int n)
{
   n=to_string(n)[0]-'0';
   return n;


}

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int i, count = 0, j,fdgt,ldgt;
        int len = nums.size();
        for (i = 0; i < len - 1; i++) {
            fdgt=find_fdgt(nums[i]);
            for (j = i + 1; j < len; j++) {
                ldgt=nums[j]%10;
                if (gcd(fdgt, ldgt) == 1)
                    count += 1;
            }
        }
        return count;
    }
};

int main()
{
    Solution a;
    vector<int> nums ={2,5,1,4};

    cout << a.countBeautifulPairs(nums) << endl;
    return 0;
}