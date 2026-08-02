class Solution {

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++) {

            int curr = (i == n ? 0 : heights[i]);

            while(!st.empty() && curr < heights[st.top()]) {

                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int area = heights[element] * (nse - pse - 1);

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }


public:

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m,0);

        int maxArea = 0;


        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '1') {
                    height[j]++;
                }
                else {
                    height[j] = 0;
                }
            }

            int area = largestRectangleArea(height);

            maxArea = max(maxArea, area);
        }


        return maxArea;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna