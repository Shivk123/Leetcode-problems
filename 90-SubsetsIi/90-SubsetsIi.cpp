// Last updated: 5/28/2025, 9:55:37 PM
class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
               int idx) {
        ans.push_back(temp);
        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            solve(nums, ans, temp, i + 1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        solve(nums, ans, subset, 0);
        return ans;
    }
};