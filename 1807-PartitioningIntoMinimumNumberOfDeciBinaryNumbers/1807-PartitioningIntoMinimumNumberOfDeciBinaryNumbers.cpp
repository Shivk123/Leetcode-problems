// Last updated: 5/28/2025, 9:52:37 PM
class Solution {
public:
    int minPartitions(string n) {
        int a=0;
        for(char c:n){
            a=max(a,c-'0');
            if(a==9)break;
        }
        return a;
    }
};