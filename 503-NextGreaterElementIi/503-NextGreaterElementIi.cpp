// Last updated: 5/28/2025, 9:54:46 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> monostack;

        for (int i = 2*n - 1; i > -1; i--) {
            while (!monostack.empty() && monostack.top() <= nums[i%n]) {
                monostack.pop();
            }
            if (!monostack.empty())
                ans[i%n] = monostack.top();

            monostack.push(nums[i%n]);
        }
        return ans;
    }
};