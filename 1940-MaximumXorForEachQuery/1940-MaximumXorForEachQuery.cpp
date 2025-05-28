// Last updated: 5/28/2025, 9:52:17 PM
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int i = 0,j=pow(2,maximumBit) - 1;
        for(auto it : nums){
            i^=it;
            ans.push_back(j-i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};