// Last updated: 5/28/2025, 9:50:57 PM
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        constexpr int kMax = 9 * 9;
        int ans = -1;
        vector<vector<int>> count(kMax + 1);

        for (const int num : nums)
            count[getDigitSum(num)].push_back(num);

        for (vector<int>& groupNums : count) {
            if (groupNums.size() < 2)
                continue;
            ranges::sort(groupNums, greater<>());
            ans = max(ans, groupNums[0] + groupNums[1]);
        }

        return ans;
    }

private:
    int getDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }
};