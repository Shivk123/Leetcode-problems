// Last updated: 5/28/2025, 9:50:27 PM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countOfOnesOrGreater =
            nums.end() - std::lower_bound(nums.begin(), nums.end(), 1);
        int countBeforeFirstOne =
            std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return std::max(countOfOnesOrGreater, countBeforeFirstOne);
    }
};