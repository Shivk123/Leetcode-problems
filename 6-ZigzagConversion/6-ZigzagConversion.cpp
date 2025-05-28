// Last updated: 5/28/2025, 9:56:27 PM
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() < 3)
            return s;

        string ans;
        for (int i = 0; i < numRows; i++) {
            int inc = 2 * (numRows - 1);
            for (int j = i; j < s.length(); j += inc) {
                ans += s[j];
                if (0 < i && i < numRows - 1 && j + inc - 2 * i < s.length()) {
                    ans += s[j + inc - 2 * i];
                }
            }
        }
        return ans;
    }
};