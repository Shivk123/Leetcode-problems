class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n=nums.size();
        k=k%n;
        if(k==0)return;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};