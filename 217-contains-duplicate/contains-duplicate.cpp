class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,bool> count;
        for(int i=0;i<n;i++){
            if(count[nums[i]])return true;
            count[nums[i]]=true;
        }
        return false;
    }
};