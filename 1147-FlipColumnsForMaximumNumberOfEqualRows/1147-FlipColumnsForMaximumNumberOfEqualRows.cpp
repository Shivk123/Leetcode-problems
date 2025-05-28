// Last updated: 5/28/2025, 9:53:48 PM
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;
        int maxEqualRows = 0;

        for (auto& row : matrix) {
            string pattern;

            for (int cell : row) {
                char representation = '0' + (row[0] == 0 ? cell : cell ^ 1);
                pattern.push_back(representation);
            }

            int currentCount = ++patternCount[pattern];
            maxEqualRows = max(maxEqualRows, currentCount);
        }

        return maxEqualRows;
    }
};