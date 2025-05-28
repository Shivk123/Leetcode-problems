// Last updated: 5/28/2025, 9:48:40 PM
class Solution {
public:
    string compressedString(string word) {
        char d;
        int cnt = 0;
        string ans;
        for (char c : word) {
            if (d != c) {
                while (cnt) {
                    ans += to_string(min(cnt, 9)) + d;
                    cnt = (cnt > 9) ? cnt - 9 : 0;
                }
                d = c;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        while (cnt) {
            ans += to_string(min(cnt, 9)) + d;
            cnt = (cnt > 9) ? cnt - 9 : 0;
        }
        return ans;
    }
};