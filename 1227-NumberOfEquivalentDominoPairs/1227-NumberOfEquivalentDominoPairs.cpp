// Last updated: 5/28/2025, 9:53:39 PM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> m;
        for(vector<int> it: dominoes){
            if(it[0]>it[1]){
                m[it[1]*10+it[0]]++;
            }
            else{
                m[it[0]*10+it[1]]++;
            }
        }
        int ans=0;
        for(auto it: m){
            ans+=((it.second)*(it.second-1)/2);
        }
        return ans;
    }
};