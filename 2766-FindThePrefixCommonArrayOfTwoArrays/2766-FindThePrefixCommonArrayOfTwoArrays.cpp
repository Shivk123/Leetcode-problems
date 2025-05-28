// Last updated: 5/28/2025, 9:49:59 PM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        int c = 0;
        vector<int> ans,d(n);

        for (int i = 0; i < n; i++) {
            if (++d[A[i]-1] == 0)
                c++;
            if (--d[B[i]-1] == 0)
                c++;
            ans.push_back(c);
        }
        return ans;
    }
};