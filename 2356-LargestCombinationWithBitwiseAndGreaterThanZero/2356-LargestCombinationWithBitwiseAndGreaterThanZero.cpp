// Last updated: 5/28/2025, 9:51:12 PM
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size(), ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (auto candidate : candidates) {
                if (candidate & (1 << i))
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};