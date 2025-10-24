class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,cnt=0;
        unordered_map<int,int> bag;
        bag[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            cnt+=bag[sum-k];
            bag[sum]++;
        }
        return cnt;
    }
};