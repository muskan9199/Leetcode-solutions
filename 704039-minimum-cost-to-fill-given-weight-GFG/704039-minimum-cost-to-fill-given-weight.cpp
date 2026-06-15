class Solution {
public:
    int minimumCost(vector<int> &cost, int w) {
        int n = cost.size();
        vector<int> dp(w + 1, 1e9);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (cost[i] == -1) continue;
            
            int weight = i + 1;
            int price = cost[i];

            for (int j = weight; j <= w; j++) {
                if (dp[j - weight] != 1e9) {
                    dp[j] = min(dp[j], dp[j - weight] + price);
                }
            }
        }

        return dp[w] == 1e9 ? -1 : dp[w];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna