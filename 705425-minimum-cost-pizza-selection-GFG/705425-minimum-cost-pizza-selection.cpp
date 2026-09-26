class Solution {
public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        vector<int> dp(x + 101, 1e9);
        dp[0] = 0;

        int max_cap = x + 100;
        for (int i = 0; i <= max_cap; i++) {
            if (dp[i] == 1e9) continue;
            if (i + s <= max_cap) dp[i + s] = min(dp[i + s], dp[i] + cs);
            if (i + m <= max_cap) dp[i + m] = min(dp[i + m], dp[i] + cm);
            if (i + l <= max_cap) dp[i + l] = min(dp[i + l], dp[i] + cl);
        }

        int ans = 1e9;
        for (int i = x; i <= max_cap; i++) {
            ans = min(ans, dp[i]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna