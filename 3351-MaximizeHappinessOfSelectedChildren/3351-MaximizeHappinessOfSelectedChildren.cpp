// Last updated: 6/1/2025, 1:00:27 AM
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.begin(), happiness.end());
        for(int i=0 ; i<k;i++){
            int c=(happiness[happiness.size()-1-i]-i);
            ans+=max(c,0);
        }
        return ans;
    }
};