class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse top row
            for (int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);
            top++;

            // Traverse right column
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // Traverse bottom row (if still in range)
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Traverse left column (if still in range)
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};
