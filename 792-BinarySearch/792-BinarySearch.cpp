// Last updated: 5/28/2025, 9:54:20 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0, high= nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};