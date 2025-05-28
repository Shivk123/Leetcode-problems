// Last updated: 5/28/2025, 9:55:21 PM
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> sequenceCount;
        int possibleStarts = s.size() - 9;

        std::vector<std::string> repeats;
        for (int i = 0; i < possibleStarts; ++i) {
            std::string subsequence = s.substr(i, 10);
            if (++sequenceCount[subsequence] == 2) {
                repeats.push_back(subsequence);
            }
        }
        return repeats;
    }
};