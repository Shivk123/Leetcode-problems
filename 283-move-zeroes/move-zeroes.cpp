class Solution {

public:
    void moveZeroes(vector<int>& nums) {
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(j!=i)swap(nums[++j],nums[i]);
            }
        }
    }
};