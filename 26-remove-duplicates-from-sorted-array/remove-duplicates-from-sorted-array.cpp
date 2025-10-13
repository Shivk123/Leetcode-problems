class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> bag;
        for(int i=0;i<nums.size();i++){
            bag.insert(nums[i]);
        }
        nums.assign(bag.begin(),bag.end());
        return bag.size();
    }
};