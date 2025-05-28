// Last updated: 5/28/2025, 9:55:52 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        while (ss >> s);
        return s.length();
    }
};