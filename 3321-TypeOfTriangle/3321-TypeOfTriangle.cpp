// Last updated: 5/28/2025, 9:48:59 PM
class Solution {
public:
    string triangleType(vector<int>& nums) {
        ranges::sort(nums);
        if (nums[0] + nums[1] <= nums[2])
            return "none";
        if (nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";
        if (nums[0] == nums[1] || nums[1] == nums[2])
            return "isosceles";
        return "scalene";
    }
};