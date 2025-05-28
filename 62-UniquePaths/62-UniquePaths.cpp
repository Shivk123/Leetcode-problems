// Last updated: 5/28/2025, 9:55:48 PM
class Solution {
    public:
    int com(int m,int n){
        long long a=m;
        for(int i=2;i<n;i++){
            a*=(m-i+1);
            a/=i;
        }
        return a;
    }
    int uniquePaths(int m, int n) {
        if(m==1||n==1)return 1;
        return com(m+n-2,min(m,n));
    }
};