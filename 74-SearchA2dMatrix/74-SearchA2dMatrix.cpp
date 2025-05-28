// Last updated: 5/28/2025, 9:55:42 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, m=matrix.size(),n=matrix[0].size(),high=n*m - 1;
        while(low<=high){
            int mid=(low+high)/2;
            int temp= matrix[mid/n][mid%n];
            if(temp==target)return true;
            else if(temp>target)high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};