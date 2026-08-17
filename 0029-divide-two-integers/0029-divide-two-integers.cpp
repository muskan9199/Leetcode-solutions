class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle 32-bit overflow edge case: INT_MIN / -1 = 2^31, which exceeds INT_MAX
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert operands to negative numbers to prevent overflow when converting INT_MIN to positive
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        // Exponential subtraction using bit shifts
        while (n >= d) {
            long long temp = d;
            long long multiple = 1;

            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            quotient += multiple;
        }

        return isNegative ? -quotient : quotient;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna