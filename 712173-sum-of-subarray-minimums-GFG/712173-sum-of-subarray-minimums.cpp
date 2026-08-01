class Solution {
    vector<int> nextSmallerElements(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;
        vector<int> nse(n);

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                nse[i] = n;
            }
            else {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }


    vector<int> previousSmallerElements(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                pse[i] = -1;
            }
            else {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }


public:

    int sumSubMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> nse = nextSmallerElements(arr);
        vector<int> pse = previousSmallerElements(arr);

        long long totalSum = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long contribution = (left * right * arr[i]) % mod;
            totalSum = (totalSum + contribution) % mod;
        }
        return totalSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna