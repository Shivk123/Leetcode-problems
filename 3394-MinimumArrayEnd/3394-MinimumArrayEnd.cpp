// Last updated: 5/28/2025, 9:48:50 PM
class Solution {
public:
    long long minEnd(int n, int x) {
        const int kMaxBit = log2(n) + log2(x) + 2;
        const long k = n - 1;
        long ans = x;
        int kBinaryIndex = 0;

        for (int i = 0; i < kMaxBit; ++i) {
            if ((ans >> i & 1) == 0) {
                if (k >> kBinaryIndex & 1)
                    ans |= 1L << i;
                ++kBinaryIndex;
            }
        }

        return ans;
    }
};