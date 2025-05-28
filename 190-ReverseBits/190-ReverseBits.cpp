// Last updated: 5/28/2025, 9:55:19 PM
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversedNumber = 0;

        for (int bitPosition = 0; bitPosition < 32; ++bitPosition) {
            reversedNumber |= (n & 1) << (31 - bitPosition);
            n >>= 1;
        }

        return reversedNumber;
    }
};