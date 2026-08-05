class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;

        int maxArea = 0;

        vector<int> nse(n);
        vector<int> pse(n);


        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[i] < heights[st.top()]) {

                int element = st.top();
                st.pop();

                nse[element] = i;

                pse[element] = st.empty() ? -1 : st.top();

                int area = heights[element] * (nse[element] - pse[element] - 1);

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        while(!st.empty()) {

            int element = st.top();
            st.pop();

            nse[element] = n;

            pse[element] = st.empty() ? -1 : st.top();

            int area = heights[element] * (nse[element] - pse[element] - 1);

            maxArea = max(maxArea, area);
        }


        return maxArea;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna