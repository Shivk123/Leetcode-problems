class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans=nums[0];
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if (prod > ans)
                    ans = prod;
            }
        }
        return ans;
    }
};