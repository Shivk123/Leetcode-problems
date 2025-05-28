// Last updated: 5/28/2025, 9:56:25 PM
class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x) {
            if (r > INT_MAX / 10 || r < INT_MIN / 10)
                return 0;
            r *= 10;
            r += x % 10;
            x /= 10;
        }

        return r;
    }
};