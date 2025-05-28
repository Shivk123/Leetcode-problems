// Last updated: 5/28/2025, 9:48:48 PM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return true;
        for(int i=1;i<n;i++){
            if(!((nums[i-1]%2)^(nums[i]%2)))return false;
        }
        return true;
    }
};