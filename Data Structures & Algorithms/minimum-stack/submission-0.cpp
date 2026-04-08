class MinStack {
public:
        stack<int> s;
        stack<int> minStack;
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minStack.push(val);
        }
        else{
            minStack.push(min(val,minStack.top()));
            s.push(val);
        }
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
