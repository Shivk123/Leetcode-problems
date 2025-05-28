// Last updated: 5/28/2025, 9:51:27 PM
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long prefix = 0;
        long mn = 0; 
        long mx = 0; 

        for (const int d : differences) {
            prefix += d;
            mn = min(mn, prefix);
            mx = max(mx, prefix);
        }

        return max(0L, (upper - lower) - (mx - mn) + 1);
    }
};