class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n= fruits.size();
        for(int fruit: fruits){
            for(int basket=0;basket<baskets.size();basket++){
                if(baskets[basket]>=fruit){
                    baskets[basket]=0;
                    n--;
                    break;
                }
            }
        }
        return n;
    }
};