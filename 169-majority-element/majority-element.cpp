class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 2 variables element count
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};