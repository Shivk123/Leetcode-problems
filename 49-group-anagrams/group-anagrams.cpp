class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        unordered_map<string, vector<string>> map;

        for (string word: words) {
            string sorted_word =word;
            sort(sorted_word.begin(), sorted_word.end());
            map[sorted_word].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto element : map) {
            ans.push_back(element.second);
        }
        return ans;
    }
};