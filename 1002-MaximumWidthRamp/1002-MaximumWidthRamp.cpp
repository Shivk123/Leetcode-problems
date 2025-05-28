// Last updated: 5/28/2025, 9:53:58 PM
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
    int ans = 0,n=nums.size();
    stack<int> stack;

    for (int i = 0; i < n; ++i)
      if (stack.empty() || nums[i] < nums[stack.top()])
        stack.push(i);

    for (int i = n - 1; i > ans; --i)
      while (!stack.empty() && nums[i] >= nums[stack.top()])
        ans = max(ans, i - stack.top()), stack.pop();

    return ans;
    }
};