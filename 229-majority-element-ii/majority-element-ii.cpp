class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // MODIFIED MOORE VOTING ALGO
        int e1,e2=1,c1=0,c2=0,n=nums.size()/3;
        for(int i: nums){
            if(c1==0 && i!=e2){
                e1=i;
                c1=1;
            }
            else if(c2==0 && i!=e1){
                e2=i;
                c2=1;
            }
            else if(e1==i)c1++;
            else if(e2==i)c2++;
            else{
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        vector<int> ans;
        for(int i: nums){
            if(i==e1)c1++;
            if(i==e2)c2++;
        }
        if(c1>n)ans.push_back(e1);
        if(c2>n)ans.push_back(e2);
        return ans;
    }
};