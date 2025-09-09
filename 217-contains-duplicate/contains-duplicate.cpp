class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> visited;
        for(int it: nums){
            if(!visited[it]){
                visited[it]=true;
            }
            else{
                return true;
            }
        }
        return false;
    }
};