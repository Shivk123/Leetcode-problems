// Last updated: 5/28/2025, 9:48:53 PM
class Solution {
public:
    int scoreOfString(string s) {
        int j=0;
        for(int i=1;i<s.length();i++){
            j+=abs(s[i-1]-s[i]);
        }
        return j;
    }
};