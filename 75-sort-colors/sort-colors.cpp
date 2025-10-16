class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3];
        for (int it : nums) {
            cnt[it]++;
        }
        int j = 0;
        for (int i = 0; i < 3; i++)
            while (cnt[i]--)
                nums[j++] = i;
    }
};