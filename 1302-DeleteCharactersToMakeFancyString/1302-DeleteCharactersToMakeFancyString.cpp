// Last updated: 5/28/2025, 9:53:36 PM
class Solution {
public:
    string makeFancyString(string s) {
        int ct=0;
        string ans;
        char a=s[0];

        for(char c: s){
            if(c == a)ct++;
            else{
                a=c;
                ct=1;
            }
            if(ct<3)ans+=c;
        }
        return ans;
    }
};