// Last updated: 5/28/2025, 9:52:36 PM
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1);
        dfs(n, 0, 0, ans);
        return ans;
    }

private:
    bool dfs(int n, int i, int mask, vector<int>& ans) {
        if (i == ans.size())
            return true;
        if (ans[i] > 0)
            return dfs(n, i + 1, mask, ans);

        for (int num = n; num >= 1; --num) {
            if (mask >> num & 1)
                continue;
            if (num == 1) {
                ans[i] = num;
                if (dfs(n, i + 1, mask | 1 << num, ans))
                    return true;
                ans[i] = 0;
            } else {
                if (i + num >= ans.size() || ans[i + num] > 0)
                    continue;
                ans[i] = num;
                ans[i + num] = num;
                if (dfs(n, i + 1, mask | 1 << num, ans))
                    return true;
                ans[i + num] = 0;
                ans[i] = 0;
            }
        }

        return false;
    }
};