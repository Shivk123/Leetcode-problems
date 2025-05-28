// Last updated: 5/28/2025, 9:52:24 PM
class Solution {
public:
    bool areAlmostEqual(string str1, string str2) {
        int differenceCount = 0;
        char charFromStr1 = 0, charFromStr2 = 0;

        for (int index = 0; index < str1.size(); ++index) {
            char charA = str1[index], charB = str2[index];

            if (charA != charB) {
                if (++differenceCount > 2 ||
                    (differenceCount == 2 &&
                     (charA != charFromStr2 || charB != charFromStr1))) {
                    return false;
                }
                charFromStr1 = charA, charFromStr2 = charB;
            }
        }
        return differenceCount != 1;
    }
};