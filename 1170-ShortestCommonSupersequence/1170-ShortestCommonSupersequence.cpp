// Last updated: 5/28/2025, 9:53:45 PM
class Solution {
public:
    std::string shortestCommonSupersequence(std::string str1,
                                            std::string str2) {
        int m = str1.size();
        int n = str2.size();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        std::string sequence;
        int i = m, j = n;
        while (i > 0 || j > 0) {
            if (i == 0) {
                sequence += str2[--j];
            } else if (j == 0) {
                sequence += str1[--i];
            } else {
                if (dp[i][j] == dp[i - 1][j]) {
                    sequence += str1[--i];
                } else if (dp[i][j] == dp[i][j - 1]) {
                    sequence += str2[--j];
                } else {
                    sequence += str1[--i];
                    --j;
                }
            }
        }

        std::reverse(sequence.begin(), sequence.end());

        return sequence;
    }
};