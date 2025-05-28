// Last updated: 5/28/2025, 9:51:31 PM
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int c=0;
        for(int i=0;i<s.length();i++){
            if (c != spaces.size() && spaces[c] == i){
                c++;
                ans+=' ';
            }
            ans+=s[i];
        }
        return ans;
    }
};