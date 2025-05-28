// Last updated: 5/28/2025, 9:48:02 PM
class Solution {
public:
    string findValidPair(string s) {
        vector<int> freq(10, 0);

        string ans;
        for (char c : s) {
            freq[c - '0']++;
        }

        for (int i = 0; i < s.length() - 1; ++i) {
            int first = s[i] - '0';
            int second = s[i + 1] - '0';

            if (first != second && freq[first] == first &&
                freq[second] == second) {
                ans = string(1, s[i]) + string(1, s[i + 1]);
                return ans;
            }
        }
        return ans;
    }
};