// Last updated: 5/28/2025, 9:52:08 PM
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] += n*(nums[nums[i]]%n);
        }
        for(int i=0;i<n;i++){
            nums[i]/=n;
        }
        return nums;
    }
};