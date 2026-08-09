class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 1) return mat[0][0];

        vector<int> dp = mat[0];

        for (int i = 1; i < n; ++i) {
            int max1 = -1, max2 = -1;
            int max1_idx = -1;

            for (int j = 0; j < n; ++j) {
                if (dp[j] > max1) {
                    max2 = max1;
                    max1 = dp[j];
                    max1_idx = j;
                } else if (dp[j] > max2) {
                    max2 = dp[j];
                }
            }

            vector<int> next_dp(n);
            for (int j = 0; j < n; ++j) {
                if (j == max1_idx) {
                    next_dp[j] = mat[i][j] + max2;
                } else {
                    next_dp[j] = mat[i][j] + max1;
                }
            }
            dp = move(next_dp);
        }

        int max_sum = 0;
        for (int j = 0; j < n; ++j) {
            max_sum = max(max_sum, dp[j]);
        }

        return max_sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna