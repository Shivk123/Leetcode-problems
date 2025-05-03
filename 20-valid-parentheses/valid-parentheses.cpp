class Solution {
private:
    stack<int> st;

public:
    bool isValid(string s) {
        int n = s.length();
        while (n--) {
            if (s[n] == ')' | s[n] == '}' | s[n] == ']') {
                st.push(s[n]);
            } else {
                if(st.empty())return false;
                switch (s[n]) {
                case '(':
                    if(st.top()!=')')return false;
                    st.pop();
                    break;
                case '{':
                    if(st.top()!='}')return false;
                    st.pop();
                    break;
                case '[':
                    if(st.top()!=']')return false;
                    st.pop();
                    break;
                }
            }
        }
        return st.empty();
    }
};