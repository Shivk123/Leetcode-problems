// Last updated: 5/28/2025, 9:55:59 PM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            vector<int> temp=matrix[i];
            matrix[i]=matrix[n-1-i];
            matrix[n-1-i]=temp;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};