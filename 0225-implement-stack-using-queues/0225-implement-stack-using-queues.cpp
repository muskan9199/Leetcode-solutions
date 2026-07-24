class MyStack {

    queue<int> q;

public:

    MyStack() {
        
    }
    
    void push(int x) {

        int size = q.size();

        q.push(x);

        while(size--) {

            q.push(q.front());
            q.pop();

        }
    }
    
    int pop() {

        int value = q.front();
        q.pop();

        return value;
    }
    
    int top() {

        return q.front();
    }
    
    bool empty() {

        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna