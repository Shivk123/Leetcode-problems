// Last updated: 5/28/2025, 9:49:50 PM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        constexpr int kMax = 2000;
        const int totalDistinct =
            unordered_set<int>(nums.begin(), nums.end()).size();
        int ans = 0;
        int distinct = 0;
        vector<int> count(kMax + 1);

        int l = 0;
        for (const int num : nums) {
            if (++count[num] == 1)
                ++distinct;
            while (distinct == totalDistinct)
                if (--count[nums[l++]] == 0)
                    --distinct;
            ans += l;
        }

        return ans;
    }
};
