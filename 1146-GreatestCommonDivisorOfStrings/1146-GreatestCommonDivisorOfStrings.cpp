// Last updated: 5/28/2025, 9:53:50 PM
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2==str2+str1){
            str1=str1.substr(0,gcd(str1.length(),str2.length()));
        }
        else { str1="";}
        return str1;
    }
};