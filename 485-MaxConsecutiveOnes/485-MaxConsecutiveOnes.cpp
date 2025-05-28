// Last updated: 5/28/2025, 9:54:52 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0, ans = 0;
        for (int i : nums) {
            if (i == 1)
                c++;
            else {
                ans = max(c, ans);
                c = 0;
            }
        }
        return max(c, ans);
    }
};