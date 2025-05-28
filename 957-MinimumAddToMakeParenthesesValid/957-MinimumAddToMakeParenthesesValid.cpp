// Last updated: 5/28/2025, 9:54:01 PM
class Solution {
public:
    int minAddToMakeValid(string s) {
        int x = 0, y = 0, ans = 0;
        for (char c : s) {
            if (c == '(')
                x++;
            else {
                if (x > y)
                    y++;
                else ans++;
            }
            
        }
        return ans+x-y;
    }
};