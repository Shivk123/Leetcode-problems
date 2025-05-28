// Last updated: 5/28/2025, 9:48:28 PM
class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
};