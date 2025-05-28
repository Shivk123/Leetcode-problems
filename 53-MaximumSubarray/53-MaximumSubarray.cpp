// Last updated: 5/28/2025, 9:55:55 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ms=INT_MIN,n=nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>ms)ms=sum;
            if(sum<0)sum=0;
        }
        return ms;
    }
};