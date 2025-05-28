// Last updated: 5/28/2025, 9:50:54 PM
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<unsigned int,int> m;
        int a=0,c=0;
        for(auto it: intervals){
            m[2*it[0] - 1]++;
            m[2*it[1] + 1]--;
        }
        for(auto it: m){
            c+=it.second;
            a=max(a,c);
        }
        return a;
    }
};