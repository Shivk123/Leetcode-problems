// Last updated: 5/28/2025, 9:53:09 PM
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k)
            return false;

        bitset<26> odd;

        for (const char c : s)
            odd.flip(c - 'a');

        return odd.count() <= k;
    }
};