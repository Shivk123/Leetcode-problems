// Last updated: 5/28/2025, 9:55:32 PM
class Solution {
private:
    void solve(vector<vector<string>>& ans, string& s, vector<string>& temp,
               int idx) {
        if (idx == s.length()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(ans, s, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans, s, temp, 0);
        return ans;
    }
};