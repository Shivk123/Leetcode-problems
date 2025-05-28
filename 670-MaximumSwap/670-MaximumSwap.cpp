// Last updated: 5/28/2025, 9:54:34 PM
class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> maxIndex(n);

        iota(maxIndex.begin(), maxIndex.end(), 0);

        for (int i = n - 2; i >= 0; --i) {
            if (numStr[i] <= numStr[maxIndex[i + 1]]) {
                maxIndex[i] = maxIndex[i + 1];
            }
        }

        for (int i = 0; i < n; ++i) {
            int j = maxIndex[i];
            if (numStr[i] < numStr[j]) {
                swap(numStr[i], numStr[j]);
                break;
            }
        }

        return stoi(numStr);
    }
};