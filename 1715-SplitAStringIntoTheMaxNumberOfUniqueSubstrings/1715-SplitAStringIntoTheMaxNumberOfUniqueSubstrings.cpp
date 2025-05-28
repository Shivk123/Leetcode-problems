// Last updated: 5/28/2025, 9:52:46 PM
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    unordered_set<string> visited;  
    string inputString;
    int maxCount = 1;               

    int maxUniqueSplit(string s) {
        inputString = s;
        dfs(0, 0); 
        return maxCount;
    }

    void dfs(int startIndex, int uniqueCount) {
        if (startIndex >= inputString.size()) {
            maxCount = max(maxCount, uniqueCount);
            return;
        }

        for (int endIndex = startIndex + 1; endIndex <= inputString.size(); ++endIndex) {
            string currentSubstring = inputString.substr(startIndex, endIndex - startIndex);

            if (!visited.count(currentSubstring)) {
                visited.insert(currentSubstring);
              
                dfs(endIndex, uniqueCount + 1);

                visited.erase(currentSubstring);
            }
        }
    }
};
