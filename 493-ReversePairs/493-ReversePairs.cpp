// Last updated: 5/28/2025, 9:54:50 PM
class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        int left = low, right = mid + 1, c = 0;
        while (left <= mid) {
            if (nums[left] > 2L * nums[right]) {
                right++;
                if (right > high) {
                    c += (mid - left + 1) * (right - mid - 1);
                    break;
                }
            } else {
                left++;
                c += (right - mid - 1);
            }
        }

        left = low;
        right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= high) {
            if (nums[left] >= nums[right]) {
                temp.push_back(nums[right++]);
            } else
                temp.push_back(nums[left++]);
        }
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        return c;
    }
    int mergesort(vector<int>& nums, int low, int high) {
        if (low == high)
            return 0;
        int mid = (low + high) / 2, c = 0;
        c = mergesort(nums, low, mid) + mergesort(nums, mid + 1, high);
        return c + merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};