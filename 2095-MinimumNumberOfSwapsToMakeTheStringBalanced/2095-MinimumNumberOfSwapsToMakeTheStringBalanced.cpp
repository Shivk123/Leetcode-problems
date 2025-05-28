// Last updated: 5/28/2025, 9:51:56 PM
class Solution {
public:
    int minSwaps(string s) {
        int x = 0;
        for (const char c : s)
            if (c == '[')
                ++x;
            else if (x > 0) 
                --x;

        return (x + 1) / 2;
    }
};