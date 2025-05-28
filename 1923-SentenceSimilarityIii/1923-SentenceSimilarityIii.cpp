// Last updated: 5/28/2025, 9:52:20 PM
class Solution {
private:
    vector<string> split(string& s, char delimiter) {
        stringstream stream(s);
        string item;
        vector<string> result;

        while (getline(stream, item, delimiter)) {
            result.emplace_back(item);
        }

        return result;
    }

public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1, ' ');
        vector<string> words2 = split(sentence2, ' ');

        if (words1.size() < words2.size()) {
            swap(words1, words2);
        }

        int length1 = words1.size();
        int length2 = words2.size();

        int prefixMatch = 0;
        int suffixMatch = 0;
        while (prefixMatch < length2 &&
               words1[prefixMatch] == words2[prefixMatch]) {
            ++prefixMatch;
        }
        while (suffixMatch < length2 && words1[length1 - 1 - suffixMatch] ==
                                            words2[length2 - 1 - suffixMatch]) {
            ++suffixMatch;
        }
        return prefixMatch + suffixMatch >= length2;
    }
};