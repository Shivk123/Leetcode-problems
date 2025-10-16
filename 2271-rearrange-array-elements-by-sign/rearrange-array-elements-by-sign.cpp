class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> even, odd;
        for (int it : nums) {
            if (it > 0)
                even.push_back(it);
            else
                odd.push_back(it);
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (i % 2 == 0) ? even[i / 2] : odd[i / 2];
        }
        return nums;
    }
};