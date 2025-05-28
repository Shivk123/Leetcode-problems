// Last updated: 5/28/2025, 9:51:43 PM
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = 1e5;

        while (left < right) {
            int mid = (left + right) >> 1;
            int count = 0;

            for (int& quantity : quantities) {
                count += (quantity + mid - 1) / mid;
            }

            if (count <= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};