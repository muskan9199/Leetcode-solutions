class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++){

            while(!st.empty() && heights[st.top()] > heights[i]){

                int element = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, element * (nse - pse - 1));
            }

            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int element = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, element * (nse - pse - 1));
        }

        return maxArea;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna