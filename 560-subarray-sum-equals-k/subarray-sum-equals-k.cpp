class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,cnt=0;
        unordered_map<int,int> bag;
        for(int i=0;i<n;i++){
            bag[sum]++;
            sum+=nums[i];
            cnt+=bag[sum-k];
        }
        return cnt;
    }
};