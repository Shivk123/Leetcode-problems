// Last updated: 5/28/2025, 9:51:32 PM
#define ll long long
class Solution {
    ll sumSubarrayMins(vector<int>& arr) {
        constexpr int kMod = 1'000'000'007;
        const int n = arr.size();
        ll ans = 0;
        vector<int> prevMin(n, -1);
        vector<int> nextMin(n, n);
        stack<int> stack;

        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && arr[stack.top()] > arr[i]) {
                nextMin[stack.top()] = i;
                stack.pop();
            }
            if (!stack.empty())
                prevMin[i] = stack.top();
            stack.push(i);
        }

        for (int i = 0; i < n; ++i) {
            ans +=
                static_cast<ll>(arr[i]) * (i - prevMin[i]) * (nextMin[i] - i);
        }

        return ans;
    }
    ll sumSubarrayMax(vector<int>& arr) {
        constexpr int kMod = 1'000'000'007;
        const int n = arr.size();
        ll ans = 0;
        vector<int> prevMax(n, -1);
        vector<int> nextMax(n, n);
        stack<int> stack;

        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && arr[stack.top()] < arr[i]) {
                nextMax[stack.top()] = i;
                stack.pop();
            }
            if (!stack.empty())
                prevMax[i] = stack.top();
            stack.push(i);
        }

        for (int i = 0; i < n; ++i) {
            ans +=
                static_cast<ll>(arr[i]) * (i - prevMax[i]) * (nextMax[i] - i);
        }

        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums)-sumSubarrayMins(nums);
    }
};