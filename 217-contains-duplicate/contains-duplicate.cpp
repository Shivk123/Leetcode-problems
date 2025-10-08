class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n= nums.size();
        set<int> s;
        for(int i=0;i<n;i++){
            if(s.count(nums[i])>0)return true;
            s.insert(nums[i]);
        }
        return false;
    }
};