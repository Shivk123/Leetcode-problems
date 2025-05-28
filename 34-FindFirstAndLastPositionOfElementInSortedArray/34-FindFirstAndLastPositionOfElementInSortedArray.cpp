// Last updated: 5/28/2025, 9:56:09 PM
class Solution {
private:
    int lowerbound(vector<int>& nums, int x) {
        int low = 0, lb = nums.size(), high=lb-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= x) {
                lb = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return lb;
    }

    int upperbound(vector<int>& nums, int x) {
        int low = 0, ub = nums.size(), high = ub - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > x) {
                ub = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ub;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        int lb = lowerbound(nums, target);
        if (lb == n || nums[lb] != target)
            return {-1, -1};
        return {lb, upperbound(nums, target) - 1};
    }
};