class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=3;
        for(int i: arr){
            if(i%2==1)count--;
            else count=3;

            if(count==0)return true;
        }
        return false;
    }
};