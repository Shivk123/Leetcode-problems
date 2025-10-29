class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[low] <= nums[mid]) { //LSS is sorted
                if (nums[low] <= target && target <= nums[mid]) { //if target is in LSS
                    high = mid - 1;// Select LSS
                } else {
                    low = mid + 1;// Select RSS
                }
            } else { // RSS is sorted
                if (nums[mid] <= target && target <= nums[high]) { //if target is in RSS
                    low = mid + 1; // Select RSS
                } else {
                    high = mid - 1;// Select LSS
                }
            }
        }
        return -1;
    }
};