// Last updated: 5/28/2025, 9:53:01 PM
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        string word;
        int n=searchWord.length(),j=1;
        while (s >> word){
            for(int i=0;i<n;i++){
                if(word[i]!=searchWord[i])break;
                else if(i==n-1) return j;
            }
            j++;
        }
        return -1;
    }
};