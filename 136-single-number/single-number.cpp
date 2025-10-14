class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        //ek for loop
        for(int i=0;i<n;i++){
            //2 for loop
            bool no_duplicate=true;
            for(int j=0;j<n;j++){
                if(i!=j && nums[i]==nums[j]){
                    no_duplicate=false;
                    break;
                }
            }
            if(no_duplicate)return nums[i];
        }
        return -1;
    }
};