#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int max_vowels = 0, v = 0;
        int len = s.size();
        string vowels = "aeiou";

        // Initialize the first window
        for (int i = 0; i < k; i++)
        {
            if (vowels.find(s[i]) != string::npos)
            {
                v++;
            }
        }
        max_vowels = v;

        // Slide the window over the string
        for (int i = 1; i <= len - k; i++)
        {
            if (vowels.find(s[i - 1]) != string::npos)
            {
                v--;
            }
            if (vowels.find(s[i + k - 1]) != string::npos)
            {
                v++;
            }
            max_vowels = max(max_vowels, v);
        }
        return max_vowels;
    }
};

int main()
{
    Solution obj;
    cout << obj.maxVowels("abciiidef", 3) << endl; // Output should be 3
    return 0;
}
