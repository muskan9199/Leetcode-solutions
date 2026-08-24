class Solution {
public:
    int prefixStrings(int n) {
        long long MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = (dp[i] + (dp[j] * dp[i - 1 - j]) % MOD) % MOD;
            }
        }

        return dp[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna