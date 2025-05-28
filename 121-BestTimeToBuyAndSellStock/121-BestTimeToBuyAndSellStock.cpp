// Last updated: 5/28/2025, 9:55:34 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=0,ans=0,n=prices.size();

        for(int i=1;i<n;i++){
            if(prices[min]>prices[i]){
                min=i;
            }
            else{
                ans=max(ans,prices[i]-prices[min]);
            }
        }
        return ans;
    }
};