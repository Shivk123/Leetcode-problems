// Last updated: 5/28/2025, 9:50:36 PM
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size(),c=skill[0]+skill[n-1];
        unsigned long long int t=skill[0]*skill[n-1];
        for(int i = 1; i<n/2; i++){
            if(c!=skill[i]+skill[n-i-1])return -1;
            t+=skill[i]*skill[n-i-1];
        }
        return t;
    }
};