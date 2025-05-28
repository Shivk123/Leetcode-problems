// Last updated: 5/28/2025, 9:49:27 PM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,vector<int>& groups) {
        vector<string> ans;
        int groupId = -1;

        for (int i = 0; i < words.size(); ++i)
            if (groups[i] != groupId) {
                groupId = groups[i];
                ans.push_back(words[i]);
            }

        return ans;
    }
};