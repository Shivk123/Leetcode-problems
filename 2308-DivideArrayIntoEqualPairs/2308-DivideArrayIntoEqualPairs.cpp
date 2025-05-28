// Last updated: 5/28/2025, 9:51:15 PM
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> count(501);
        int c=0;

        for (const int num : nums){
            if(count[num]){
                c--;
                count[num]=false;
            }
            else{
                c++;
                count[num]=true;
            }
        }

        return c==0;
    }
};