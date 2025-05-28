// Last updated: 5/28/2025, 9:51:53 PM
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;

        for (int i = 0; i < nums.size(); ++i)
            ans += nums[i][i] == '0' ? '1' : '0';

        return ans;
    }
};