// Last updated: 5/28/2025, 9:53:04 PM
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int l=0;
        for(int i=0;i< candies.size();i++){
            l=max(candies[i],l);
        }
        vector<bool> a;
        for(int i=0;i< candies.size();i++){
            a.push_back(((candies[i]+extraCandies<l)? false : true));
        }
        return a;
    }
};