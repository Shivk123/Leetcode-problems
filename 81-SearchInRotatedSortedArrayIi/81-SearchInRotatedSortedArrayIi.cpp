// Last updated: 5/28/2025, 9:55:38 PM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
    }
};