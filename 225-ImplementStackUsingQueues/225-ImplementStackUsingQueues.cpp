// Last updated: 5/28/2025, 9:55:17 PM
class MyStack {
private:
    queue<int> que;

public:
    MyStack() {}

    void push(int x) {
        int n = que.size();
        que.push(x);
        while (n--) {
            que.push(que.front());
            que.pop();
        }
    }

    int pop() {
        int e = que.front();
        que.pop();
        return e;
    }

    int top() { return que.front(); }

    bool empty() { return que.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */