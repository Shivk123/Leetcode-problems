class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            auto temp= m.find(target-nums[i]);
            if(temp!=m.end())return {temp->second,i};
            m[nums[i]]=i;
        }
        return {-1,-1};
    }
};