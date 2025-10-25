class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans=nums[0] ,pre=1,suf=1;
        for (int i = 0; i < n; i++) {
            pre*=nums[i];
            if(pre>ans)ans=pre;
            if(pre==0)pre=1;

            suf*=nums[n-i-1];
            if(suf>ans)ans=suf;
            if(suf==0)suf=1;
        }
        return ans;
    }
};