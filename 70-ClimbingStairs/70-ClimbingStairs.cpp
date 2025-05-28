// Last updated: 5/28/2025, 9:55:45 PM
class Solution {
public:
    int climbStairs(int n) {
        double phi = (1 + sqrt(5)) / 2;
        return round(pow(phi, n+1) / sqrt(5));
    }
};