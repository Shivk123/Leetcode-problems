class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3];
        // count each color
        for(int it: nums){
            arr[it]++;
        }
        // modify array
        int j=0;
        for(int i=0;i<3;i++){
            while(arr[i]--){
                nums[j]=i;
                j++;
            }
        }
    }
};