class Solution {
public:
    int palindromicStrings(int n, int k) {
        long long MOD = 1e9 + 7;
        long long ans = 0;

        for (int len = 1; len <= n; len++) {
            int m = len / 2;
            if (m > k) continue;

            long long ways = 1;
            for (int i = 0; i < m; i++) {
                ways = (ways * (k - i)) % MOD;
            }

            if (len % 2 != 0) {
                ways = (ways * (k - m)) % MOD;
            }

            ans = (ans + ways) % MOD;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna