class Solution {
public:
    int maxDifference(string s) {
        int freq[26]={0};
        for(char c:s){
            freq[c-'a']++;
        }
        int even=INT_MAX,odd=1;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                if(freq[i]%2){
                    odd=max(odd,freq[i]);
                }
                else{
                    even=min(even,freq[i]);
                }
            }
        }
        return odd-even;
    }
};