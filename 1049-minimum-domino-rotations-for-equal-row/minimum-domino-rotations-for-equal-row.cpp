class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int size = tops.size();

        auto countMinRotations = [&](int x) {
            int topCount = 0, bottomCount = 0;
            for (int i = 0; i < size; ++i) {
                if (tops[i] != x && bottoms[i] != x) {
                    return size + 1;
                }
                topCount += tops[i] == x;
                bottomCount += bottoms[i] == x;
            }
            return size - max(topCount, bottomCount);
        };
        int minRotations = min(countMinRotations(tops[0]), countMinRotations(bottoms[0]));

        return minRotations > size ? -1 : minRotations;
    }
};