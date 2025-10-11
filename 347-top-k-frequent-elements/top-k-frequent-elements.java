class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();

        // Count frequencies
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // Sort keys by frequency (descending)
        List<Integer> unique = new ArrayList<>(freq.keySet());
        unique.sort((a, b) -> freq.get(b) - freq.get(a));

        // Pick top k elements
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = unique.get(i);
        }

        return result;
    }
}
