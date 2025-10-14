class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        set<int> bag;
        for(int i:nums){
            bag.insert(i);
        }
        for(int i=0;i<=n;i++){
            if(!bag.contains(i))return i;
        }
        return -1;
    }
};