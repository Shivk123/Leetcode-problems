// Last updated: 5/28/2025, 9:56:02 PM
class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0,rightMax=0,l=0,r=height.size()-1, ans=0;

        while(l<r){
            int left=height[l],right=height[r];
            if(left<=right){
                if(left<leftMax){
                    ans+=leftMax-left;
                }
                else leftMax=left;
                l++;
            }else{
                if(right<rightMax){
                    ans+=rightMax-right;
                }
                else rightMax=right;
                r--;
            }
        }
        return ans;
    }
};