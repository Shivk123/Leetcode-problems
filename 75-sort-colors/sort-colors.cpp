class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 3 var i j k
        int i = 0, j = 0, k = nums.size() - 1;
        while (j <= k) {
            // 0
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if (nums[j] == 1) { // 1
                j++;
            } else { // 2
                swap(nums[k], nums[j]);
                k--;
            }
        }
    }
};