class Solution {
    bool can_eat(vector<int>& piles, int speed, int time){
        for(int it: piles){
            time-=((it+speed-1)/speed);
            if(time<0)return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(), piles.end()),ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(can_eat(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};