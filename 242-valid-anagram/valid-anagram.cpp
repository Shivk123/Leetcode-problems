class Solution {
public:
    bool isAnagram(string s, string t) {
        int c[26];
        for(char a: s){
            c[a-'a']++;
        }
        for(char a: t){
            c[a-'a']--;
        }
        for(int i=0;i<26;i++){
            if(c[i]!=0)return false;
        }
        return true;
    }
};