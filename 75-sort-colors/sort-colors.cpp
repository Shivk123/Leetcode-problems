class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 3 var i j k
        int j = 0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=2){
                swap(nums[i],nums[j++]);
            }
        }
        n=j;
        j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=1){
                swap(nums[i],nums[j++]);
            }
        }
    }
};