// Last updated: 5/28/2025, 9:56:05 PM
class Solution {
private:
    void solve(vector<int>& candidates, vector<vector<int>>& ans,
               vector<int>& temp, int target, int idx) {
        if (idx == candidates.size()) {
            if (target == 0)
                ans.push_back(temp);
            return;
        }

        if (candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            solve(candidates, ans, temp, target - candidates[idx], idx);
            temp.pop_back();
        }
        solve(candidates, ans, temp, target, idx + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, ans, temp, target, 0);
        return ans;
    }
};