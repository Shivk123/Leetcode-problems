// Last updated: 5/28/2025, 9:49:09 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int nSquared = n * n;
        vector<int> count(nSquared + 1);

        for (const vector<int>& row : grid)
            for (const int num : row)
                ++count[num];

        int repeated = -1;
        int missing = -1;

        for (int i = 1; i <= nSquared; ++i) {
            if (count[i] == 2)
                repeated = i;
            if (count[i] == 0)
                missing = i;
        }

        return {repeated, missing};
    }
};