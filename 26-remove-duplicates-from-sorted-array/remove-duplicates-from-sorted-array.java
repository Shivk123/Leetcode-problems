class Solution {
    public int removeDuplicates(int[] nums) {
        Set<Integer> ans = new LinkedHashSet<>(); // preserves order
        for (int num : nums) {
            ans.add(num);
        }

        int i = 0;
        for (int num : ans) {
            nums[i++] = num; // copy back into nums
        }

        return ans.size();
    }
}
