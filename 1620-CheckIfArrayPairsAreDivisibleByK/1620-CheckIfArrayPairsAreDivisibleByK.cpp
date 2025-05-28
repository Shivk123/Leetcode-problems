// Last updated: 5/28/2025, 9:52:56 PM
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> m;
        for (auto it : arr) {
            int x = it % k;
            x = (x > -1) ? x : k + x;
            if (x <= k / 2)
                m[x]++;
            else
                m[k - x]--;
        }
        m[0] %= 2;
        if(k%2 == 0)m[k/2] %= 2;
        for (auto &it : m) {
            if (it.second != 0)return false;

        }
        return true;
    }
};