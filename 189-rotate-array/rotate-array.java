class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        //O(k) temp, k values
        int[] temp=new int[k];
        for(int i=n-k;i<n;i++){
            temp[i-n+k]=nums[i];
        }
        //O(n-k) nums value shift
        for(int i=n-1;i>=k;i--){
            nums[i]=nums[i-k];
        }
        //O(k) temp -> nums
        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
}