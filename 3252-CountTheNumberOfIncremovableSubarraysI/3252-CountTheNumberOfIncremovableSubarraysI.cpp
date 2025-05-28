// Last updated: 5/28/2025, 9:49:06 PM
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        const int n = nums.size();
        const int startIndex = getStartIndexOfSuffix(nums);

        if (startIndex == 0)
            return n * (n + 1) / 2;

        int ans = n - startIndex + 1;
        for (int i = 0, j = startIndex; i < startIndex; ++i) {
            if (i > 0 && nums[i] <= nums[i - 1])
                break;
            while (j < n && nums[i] >= nums[j])
                ++j;
            ans += n - j + 1;
        }

        return ans;
    }

private:
    int getStartIndexOfSuffix(const vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; --i)
            if (nums[i] >= nums[i + 1])
                return i + 1;
        return 0;
    }
};