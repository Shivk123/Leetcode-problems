// Last updated: 5/28/2025, 9:54:09 PM
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
      
        deque<int> indices;
        int minLength = n + 1;
      
        for (int i = 0; i <= n; ++i) {
            while (!indices.empty() && prefixSum[i] - prefixSum[indices.front()] >= k) {
                minLength = min(minLength, i - indices.front());
                indices.pop_front();
            }
            while (!indices.empty() && prefixSum[indices.back()] >= prefixSum[i]) {
                indices.pop_back();
            }
            indices.push_back(i);
        }
      
        return minLength > n ? -1 : minLength;
    }
};