class SpecialStack {
    stack<long long> st;
    long long mini;

  public:
    SpecialStack() {
        mini = INT_MAX;
    }

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            mini = x;
        }
        else if (x >= mini) {
            st.push(x);
        }
        else {
            st.push(2LL * x - mini);
            mini = x;
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

    int peek() {
        if (st.empty())
            return -1;

        long long curr = st.top();

        if (curr < mini)
            return mini;

        return curr;
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {
        if (st.empty())
            return -1;

        return mini;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna