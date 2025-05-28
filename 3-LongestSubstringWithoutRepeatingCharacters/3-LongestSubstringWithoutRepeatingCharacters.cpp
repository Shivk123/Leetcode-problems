// Last updated: 5/28/2025, 9:56:29 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> count(128);

        for (int l = 0, r = 0; r < s.length(); ++r) {
            ++count[s[r]];
            while (count[s[r]] > 1)
                --count[s[l++]];
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};