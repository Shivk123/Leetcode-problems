class Solution {
public:
    double myPow(double x, int n) {
        long long m = n; // Use long long to avoid overflow
        
        if (m < 0) {
            m = -m;
            x = 1.0 / x;
        }
        
        return fastPow(x, m);
    }
    
    double fastPow(double x, long long n) {
        if (n == 0) return 1;
        if (n % 2 == 0) return fastPow(x * x, n / 2);
        return x * fastPow(x * x, n / 2);
    }
};
