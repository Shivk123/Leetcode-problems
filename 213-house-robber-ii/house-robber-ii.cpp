class Solution {
    int rob1(vector<int>& nums, int low, int high) {
        int len = high - low;
        if (len == 0) return 0;
        if (len == 1) return nums[low];

        vector<int> dp(len, 0);
        dp[0] = nums[low];
        dp[1] = max(nums[low], nums[low + 1]);

        for (int i = 2; i < len; ++i) {
            dp[i] = max(nums[low + i] + dp[i - 2], dp[i - 1]);
        }

        return dp[len - 1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(rob1(nums, 0, n - 1), rob1(nums, 1, n));
    }
};
