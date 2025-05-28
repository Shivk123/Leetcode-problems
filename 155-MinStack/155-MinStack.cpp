// Last updated: 5/28/2025, 9:55:26 PM
class MinStack {
    stack<long long> st;
    long long m;

public:
    MinStack() {
        while (st.empty() == false)
            st.pop();
        m = INT_MAX;
    }

    void push(int value) {
        long long val=value;
        if (st.empty()) {
            st.push(val);
            m = val;
        } else {
            if (val < m) {
                st.push(2 * val - m);
                m = val;
            }else{
                st.push(val);
            } 
        }
    }

    void pop() {
        if (st.empty())
            return;
        long long t = st.top();
        st.pop();
        if (t < m)
            m = 2 * m - t;
    }

    int top() {
        if (st.empty())
            return -1;
        if (st.top() < m)
            return m;
        return st.top();
    }

    int getMin() { return m; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */