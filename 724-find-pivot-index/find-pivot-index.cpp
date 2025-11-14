class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int n = nums.size();
        int suf = 0;
        for (int it : nums) {
            suf += it;
        }
        int pre = 0;
        for (int i = 0; i < n; i++) {
            suf -= nums[i];
            if (pre == suf)
                return i;
            pre += nums[i];
        }
        return -1;
    }
};