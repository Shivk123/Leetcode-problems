// Last updated: 5/28/2025, 9:48:41 PM
class Solution {
public:
    string clearDigits(string s) {
        string ans;

        for (const char c : s)
            if (isdigit(c))
                ans.pop_back();
            else
                ans += c;

        return ans;
    }
};