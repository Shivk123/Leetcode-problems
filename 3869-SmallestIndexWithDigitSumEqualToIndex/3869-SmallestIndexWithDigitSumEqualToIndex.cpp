// Last updated: 5/28/2025, 9:47:51 PM
class Solution {
    private:
    bool check(int& num,int &i){
        int ans=0;
        while(num){
            ans+=num%10;
            if(ans>i)return false;
            num=num/10;
        }
        return i==ans;
    }
public:
    int smallestIndex(vector<int>& nums) {
        if(nums[0]==0)return 0;
        for(int i=1;i<nums.size();i++){
            if(check(nums[i],i))return i;
        }
        return -1;
    }
};