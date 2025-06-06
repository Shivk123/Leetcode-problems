// Last updated: 5/28/2025, 9:54:58 PM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        return knapsack(nums, sum / 2);
    }

private:
    bool knapsack(const vector<int>& nums, int subsetSum) {
        vector<bool> dp(subsetSum + 1);
        dp[0] = true;

        for (const int num : nums)
            for (int i = subsetSum; i >= num; --i)
                dp[i] = dp[i] || dp[i - num];

        return dp[subsetSum];
    }
};