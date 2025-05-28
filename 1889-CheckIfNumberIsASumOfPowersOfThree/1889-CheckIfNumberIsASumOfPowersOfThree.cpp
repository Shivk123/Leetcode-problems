// Last updated: 5/28/2025, 9:52:26 PM
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 1) {
            const int r = n % 3;
            if (r == 2)
                return false;
            n /= 3;
        }

        return true;
    }
};