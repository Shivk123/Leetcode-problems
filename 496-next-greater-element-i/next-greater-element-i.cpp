class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> m;
        stack<int> s;

        const int n=nums2.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] >= s.top())
                s.pop();
            m[nums2[i]] = (s.empty()) ? -1 : s.top();
            s.push(nums2[i]);
        }
        for (int it : nums1) {
            ans.push_back(m[it]);
        }
        return ans;
    }
};