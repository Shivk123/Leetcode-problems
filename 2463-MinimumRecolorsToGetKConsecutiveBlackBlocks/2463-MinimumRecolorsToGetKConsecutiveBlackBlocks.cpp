// Last updated: 5/28/2025, 9:50:59 PM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int countB = 0;
        int maxCountB = 0;

        for (int i = 0; i < blocks.length(); ++i) {
            if (blocks[i] == 'B')
                ++countB;
            if (i >= k && blocks[i - k] == 'B')
                --countB;
            maxCountB = max(maxCountB, countB);
        }

        return k - maxCountB;
    }
};