class Solution {
public:

    bool isPossible(long long mid, long long h, vector<int>& t) {
        long long reduced = 0;
        for (long long i = 0; i < t.size(); i++) {
            long long low = 1, high = 1e6, max_n = 0; // High limit based on constraints
            
            // Binary search for max n such that t[i] * (n * (n + 1) / 2) <= mid
            while (low <= high) {
                long long n = low + (high - low) / 2;
                long long work = t[i] * (n * (n + 1)) / 2;
                
                if (work <= mid) {
                    max_n = n; // Store the maximum valid n
                    low = n + 1;
                } else {
                    high = n - 1;
                }
            }
            
            reduced += max_n;
            
            // If we already meet or exceed the required height
            if (reduced >= h) {
                return true;
            }
        }
        return false;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long high = 1e16;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
