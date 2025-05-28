// Last updated: 5/28/2025, 9:52:28 PM
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i,n1=(int)word1.length(),n2=(int)word2.length();
        string s;
        
        for (i=0;i<(max(n1,n2));i++){
            if(i<n1)s+=word1[i];
            if(i<n2)s+=word2[i];
        }
        return s;
    }
};