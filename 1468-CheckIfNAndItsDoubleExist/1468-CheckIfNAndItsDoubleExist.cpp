// Last updated: 5/28/2025, 9:53:20 PM
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;

        for (const int a : arr) {
            if (seen.contains(a * 2) || a % 2 == 0 && seen.contains(a / 2))
                return true;
            seen.insert(a);
        }

        return false;
    }
};