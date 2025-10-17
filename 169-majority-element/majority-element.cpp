class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0], cnt = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == num)
                cnt++;
            else {
                if (cnt == 0) {
                    num = nums[i];
                    cnt = 1;
                } else
                    cnt--;
            }
        }
        return num;
    }
};