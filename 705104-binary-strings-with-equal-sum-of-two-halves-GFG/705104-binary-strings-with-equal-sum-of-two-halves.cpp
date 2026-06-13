class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        long long mod = 1e9 + 7;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        long long mod = 1e9 + 7;
        return power(n, mod - 2);
    }

    int computeValue(int n) {
        long long mod = 1e9 + 7;
        long long num = 1, den = 1;

        for (int i = 1; i <= n; i++) {
            num = (num * (n + i)) % mod;
            den = (den * i) % mod;
        }

        return (num * modInverse(den)) % mod;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna