// Last updated: 5/28/2025, 9:53:25 PM
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) { 
                    dp[i][j] = matrix[i][j];
                } else if (matrix[i][j] == 1) {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};