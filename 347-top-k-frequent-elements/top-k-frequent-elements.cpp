class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<int> res;
        for (auto& it : freq) {
            res.push_back(it.first);
        }

        // Sort by frequency (descending)
        sort(res.begin(), res.end(), [&](int a, int b) {
            return freq[a] > freq[b];
        });

        // Return top k elements
        return vector<int>(res.begin(), res.begin() + k);
    }
};