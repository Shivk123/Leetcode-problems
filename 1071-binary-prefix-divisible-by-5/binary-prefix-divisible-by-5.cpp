class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int pre=0;
        vector<bool> ans;
        for(int it: nums){
            pre=(pre*2)%5+it;
            ans.push_back((pre%5==0));
        }
        return ans;
    }
};