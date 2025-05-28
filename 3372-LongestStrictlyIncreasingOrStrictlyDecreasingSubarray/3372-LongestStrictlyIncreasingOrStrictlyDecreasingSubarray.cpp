// Last updated: 5/28/2025, 9:48:54 PM
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=1,d=1,a=1,n=nums.size();
        for(int j=1;j<n;j++){
            if(nums[j-1]==nums[j]){
                i=1;
                d=1;
            }
            else if(nums[j-1]<nums[j]){
                i++;
                d=1;
            }
            else{
                d++;
                i=1;
            }
            a=max({a,i,d});
        }
        return a;
    }
};