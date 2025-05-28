// Last updated: 5/28/2025, 9:48:07 PM
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();

        for (int i = 0; i <= n - k; i++) {
            if (count(s.begin() + i, s.begin() + i + k, s[i]) == k) {
                if ((i == 0 || s[i - 1] != s[i]) &&
                    (i + k == n || s[i + k] != s[i])) {
                    return true;
                }
            }
        }

        return false;
    }
};
