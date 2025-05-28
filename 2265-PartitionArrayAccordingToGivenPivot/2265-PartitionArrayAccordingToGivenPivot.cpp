// Last updated: 5/28/2025, 9:51:23 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        for (const int num : nums)
            if (num < pivot)
                ans.push_back(num);

        for (const int num : nums)
            if (num == pivot)
                ans.push_back(num);

        for (const int num : nums)
            if (num > pivot)
                ans.push_back(num);

        return ans;
    }
};