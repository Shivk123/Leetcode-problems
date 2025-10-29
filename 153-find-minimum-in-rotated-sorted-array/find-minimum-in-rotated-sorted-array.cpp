class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, ans=nums[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[low] < nums[high]){
                if(nums[low]<ans)ans=nums[low];
                break;
            }
            else if (nums[low] <= nums[mid]) {
                if(nums[low]<ans)ans=nums[low];
                low=mid+1;
            } else {
                if(nums[mid]<ans)ans=nums[mid];
                high=mid-1;
            }
        }
        return ans;
    }
};