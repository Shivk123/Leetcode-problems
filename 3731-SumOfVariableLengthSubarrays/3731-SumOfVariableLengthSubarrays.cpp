// Last updated: 5/28/2025, 9:48:03 PM
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = max(0, i - nums[i]); j < i + 1; j++) {
                sum += nums[j];
            }
        }
        return sum;
    }
};