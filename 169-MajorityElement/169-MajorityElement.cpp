// Last updated: 5/28/2025, 9:55:22 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e , cnt = 0;

        for (int i :nums) {
            if (cnt == 0) {
                e = i;
                cnt = 1;
            } else {
                if (e == i)
                    cnt++;
                else
                    cnt--;
            }
        }
        return e;
    }
};