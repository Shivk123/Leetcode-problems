class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 2 variables element count
        int ele=nums[0],cnt=1;
        for(int i=1;i<nums.size();i++){
            if(ele==nums[i]){
                cnt++;
            }else{
                if(cnt==0){
                    ele=nums[i];
                    cnt=1;
                }
                else{
                    cnt--;
                }
            }
        }
        return ele;
    }
};