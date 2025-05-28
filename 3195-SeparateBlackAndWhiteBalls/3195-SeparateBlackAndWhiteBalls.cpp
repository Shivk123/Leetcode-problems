// Last updated: 5/28/2025, 9:49:13 PM
class Solution {
public:
    long long minimumSteps(string s) {
        int c=0,n=s.length();
        unsigned long long int swaps=0;
        while(n--){
            if(s[n]=='0'){
                swaps+=n-c++;
            }
        }
        return swaps;
    }
};