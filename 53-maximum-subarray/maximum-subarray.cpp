class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN, max_sum = sum;
        for (int front = 0; front < nums.size(); front++) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[front];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};