// Last updated: 5/28/2025, 9:48:49 PM
class Solution {
 public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    vector<bool> ans;
    int id = 0;
    vector<int> parityIds = {id};

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] % 2 == nums[i - 1] % 2)
        ++id;
      parityIds.push_back(id);
    }

    for (const vector<int> query : queries) {
      const int from = query[0];
      const int to = query[1];
      ans.push_back(parityIds[from] == parityIds[to]);
    }

    return ans;
  }
};