// Last updated: 5/28/2025, 9:49:58 PM
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(derived.begin(), derived.end(), 0, bit_xor<>()) == 0;
    }
};