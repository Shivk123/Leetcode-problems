// Last updated: 5/28/2025, 9:51:17 PM
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> charCounts(26, 0);
        for (char ch : s) {
            charCounts[ch - 'a']++;
        }

        string result;

        for (int i = 25; i >= 0; --i) {
            int nextCharIndex = i - 1;

            while (true) {
                int repeatCount = min(charCounts[i], repeatLimit);
                for (int k = repeatCount; k > 0; --k) {
                    charCounts[i]--;
                    result.push_back('a' + i);
                }

                if (charCounts[i] == 0) break;

                while (nextCharIndex >= 0 && charCounts[nextCharIndex] == 0) {
                    --nextCharIndex;
                }
              
                if (nextCharIndex < 0) break;

                charCounts[nextCharIndex]--;
                result.push_back('a' + nextCharIndex);
            }
        }

        return result;
    }
};