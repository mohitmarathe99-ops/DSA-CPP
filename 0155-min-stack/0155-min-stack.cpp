class MinStack {
private:
    std::stack<long long> st;
    long long minVal;
public:
    MinStack() {
        minVal = INT_MAX;
    }
    void push(int val) {
        long long value = val;
        if (st.empty()) {
            minVal = value;
            st.push(value);
        } else if (value < minVal) {
            st.push(2 * value - minVal);
            minVal = value;
        } else {
            st.push(value);
        }
    }
    void pop() {
        if (st.empty()) return;
        long long topVal = st.top();
        st.pop();
        
        if (topVal < minVal) {
            minVal = 2 * minVal - topVal;
        }
    }
    int top() {
        long long topVal = st.top();
        if (topVal < minVal) {
            return minVal;
        }
        return topVal;
    }
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */