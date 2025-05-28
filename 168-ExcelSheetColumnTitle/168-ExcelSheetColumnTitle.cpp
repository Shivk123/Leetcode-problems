// Last updated: 5/28/2025, 9:55:24 PM
class Solution {
 public:
  string convertToTitle(int n) {
    return n == 0 ? "": convertToTitle((n - 1) / 26) + (char)('A' + ((n - 1) % 26));
  }
};