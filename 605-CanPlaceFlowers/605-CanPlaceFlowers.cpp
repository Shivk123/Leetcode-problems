// Last updated: 5/28/2025, 9:54:41 PM
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int r=0,c=0;
        for (int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                r++;
            }
            else{
                r-=1;
                if(r>0)c+=(r/2)+(r%2);
                r=-1;
            }
        }
        if(r>0)c+=(r/2)+(r%2);
        cout<<c;
        if(c<n)return false;
        else return true;
    }
};