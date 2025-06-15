class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int back = 0, sum = nums[back], max_sum = sum;
        for (int front = 1; front < nums.size(); front++) {
            if (sum < 0) {
                sum = 0;
                back = front;
            }
            sum += nums[front];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};