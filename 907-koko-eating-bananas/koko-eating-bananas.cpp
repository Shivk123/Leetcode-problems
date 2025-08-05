#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& piles, int mid,int h){
        for(int it: piles){
            h-=ceil((double)it / mid);
            if(h<0)return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(), piles.end()),ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(piles,mid,h)){
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