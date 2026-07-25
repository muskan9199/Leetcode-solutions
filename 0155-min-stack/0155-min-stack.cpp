#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = INT_MAX;
    }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mini = value;
        }
        else if (value >= mini) {
            st.push(value);
        }
        else {
            st.push(2LL * value - mini);
            mini = value;
        }
    }

    void pop() {
        if (st.empty())
            return;

        long long curr = st.top();
        st.pop();

        if (curr < mini) {
            mini = 2LL * mini - curr;
        }
    }

    int top() {
        if (st.empty())
            return -1;

        long long curr = st.top();

        if (curr < mini) {
            return mini;
        }

        return curr;
    }

    int getMin() {
        if (st.empty())
            return -1;

        return mini;
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

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna