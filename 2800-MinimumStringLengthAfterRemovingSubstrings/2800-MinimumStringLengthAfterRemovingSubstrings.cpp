// Last updated: 5/28/2025, 9:49:56 PM
class Solution {
public:
    int minLength(string s) {
        if(s.length()==1)return 1;
        stack<char> stack;
        stack.push('Z');
        for (char c : s) {
            if((c=='B'&&stack.top()=='A')||(c=='D'&&stack.top()=='C')){
                stack.pop();
                continue;
            }
            stack.push(c);
        }
        return stack.size()-1;
    }
};