class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> res(n - k + 1);
        for (int i = 0; i < n; i++) {
            if (!q.empty() && q.front() < i - k + 1)
                q.pop_front();

            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();

            q.push_back(i);

            if (i >= k - 1)
                res[i - k + 1] = nums[q.front()];
        }
        return res;
    }
};