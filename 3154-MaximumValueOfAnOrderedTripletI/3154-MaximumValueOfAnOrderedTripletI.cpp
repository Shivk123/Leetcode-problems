// Last updated: 5/28/2025, 9:49:24 PM
class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    long ans = 0;
    int maxDiff = 0;
    int maxNum = 0;

    for (const int num : nums) {
      ans = max(ans, static_cast<long>(maxDiff) * num);
      maxDiff = max(maxDiff, maxNum - num);            
      maxNum = max(maxNum, num);                       
    }

    return ans;
  }
};