//only functional part

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();
        int val, carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            val = (digits[i] + carry);
            if (val < 10)
                carry = 0;
            else {
                val = 0;
                carry = 1;
            }

            digits[i] = val;
        }
        if(carry==1)
        {
            digits.insert(digits.begin()+0,1);
        }
        return digits;
    }
};
