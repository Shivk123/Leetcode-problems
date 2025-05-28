// Last updated: 5/28/2025, 9:56:20 PM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ranges::sort(nums);
        const int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i-1]==nums[i])continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j-1]==nums[j])continue;
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k++],nums[l--]});
                        while(k<l && nums[l]==nums[l+1])l--;
                        while(k<l && nums[k]==nums[k-1])k++;
                    }
                    else if(sum>target)l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};