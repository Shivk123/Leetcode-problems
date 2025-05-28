// Last updated: 5/28/2025, 9:53:06 PM
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (const string& a : words)
            for (const string& b : words)
                if (a.length() < b.length() && b.find(a) != string::npos) {
                    ans.push_back(a);
                    break;
                }
        return ans;
    }
};