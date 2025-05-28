// Last updated: 5/28/2025, 9:52:19 PM
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0,n=nums.size(),sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                sum+=nums[i];
            }
            else {
                ans=max(ans,sum);
                sum=nums[i];
            }
        }
        return max(sum,ans);
    }
};