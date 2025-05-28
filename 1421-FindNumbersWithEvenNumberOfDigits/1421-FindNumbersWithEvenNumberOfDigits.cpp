// Last updated: 5/28/2025, 9:53:23 PM
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int it: nums){
            if(to_string(it).length()%2==0)ans++;
        }
        return ans;
    }
};