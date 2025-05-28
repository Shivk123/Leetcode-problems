// Last updated: 5/28/2025, 9:52:16 PM
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; ++i)
            ans = (ans + k) % i;
        return ans + 1;
    }
};