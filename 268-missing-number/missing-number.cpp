class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        //nums ka XOR
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }        
        //Actual num ka XOR
        for(int i=0;i<=n;i++){
            ans^=i;
        }
        return ans;
    }
};