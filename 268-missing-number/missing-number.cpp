class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        //nums ka XOR
        for(int i=0;i<n;i++){
            ans^=i^nums[i];
        }        
        return ans;
    }
};