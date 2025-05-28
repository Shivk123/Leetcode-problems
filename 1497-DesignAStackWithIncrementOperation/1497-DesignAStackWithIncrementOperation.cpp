// Last updated: 5/28/2025, 9:53:13 PM
class CustomStack {
private:
vector<int> stack;
int n;
public:
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(stack.size()!= n) stack.push_back(x);
    }
    
    int pop() {
        if(stack.empty())return -1;
        int y = stack[stack.size()-1];
        stack.pop_back();
        return y;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min((int)stack.size(),k);i++){
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */