// Last updated: 5/28/2025, 9:48:09 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int rsum= accumulate(nums.begin(),nums.end(),0),lsum=0,n=nums.size(),ans=0;
        for(int i=0;i<n-1;i++){
            lsum+=nums[i];
            rsum-=nums[i];
            if(abs(rsum-lsum)%2==0)ans++;
            
        }
        return ans;
    }
};