// Last updated: 5/28/2025, 9:53:40 PM
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> m;
        for (auto it : arr)
            m[it]=0;
        int i=1;
        for (auto it : m){
            m[it.first]=i++;
        }
        for (int i = 0; i<arr.size(); i++) arr[i]=m[arr[i]];
        return arr;
    }
};