// Last updated: 5/28/2025, 9:56:24 PM
class Solution {
public:
    int romanToInt(string s) {
        map <char,int> roman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int value = 0;
        for( int i = 0; i<s.length()-1; i++){
            if(roman[s[i]]<roman[s[i+1]]) value-=roman[s[i]];
            else  value+=roman[s[i]];
        }
        value+=roman[s.back()];

        return value;
    }
};