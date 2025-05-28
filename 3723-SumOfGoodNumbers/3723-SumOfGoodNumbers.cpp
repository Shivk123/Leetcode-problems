// Last updated: 5/28/2025, 9:48:05 PM
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int l=-k,r=k,sum=0,n=nums.size();
        for(int i=0;i<n;i++,l++,r++){
            if(l>=0){
                if(nums[i]<=nums[l])continue;
            }
            if(r<n){
                if(nums[i]<=nums[r])continue;
            }
            sum+=nums[i];
        }
        return sum;
    }
};