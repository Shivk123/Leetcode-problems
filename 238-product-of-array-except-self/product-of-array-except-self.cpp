class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //create ans
        int n=nums.size();
        vector<int> ans(n,1),prefix(n,1),suffix(n,1);
        int prod=nums[0];
        // calc pref
        for(int i=1;i<n;i++){
            prefix[i]=prod;
            prod*=nums[i];
        }
        // calc suff
        prod=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=prod;
            prod*=nums[i];
        }
        // calc ans = pref*suff
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
};