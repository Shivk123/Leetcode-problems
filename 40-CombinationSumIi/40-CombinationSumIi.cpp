// Last updated: 5/28/2025, 9:56:04 PM
class Solution {
private:
    void solve(vector<int>& candidates, vector<vector<int>>& ans,
               vector<int>& temp, int target, int idx) {
        // base case
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            int t = candidates[i];
            if (t > target)
                break;
            temp.push_back(t);
            solve(candidates, ans, temp, target - t, i + 1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, ans, temp, target, 0);
        return ans;
    }
};