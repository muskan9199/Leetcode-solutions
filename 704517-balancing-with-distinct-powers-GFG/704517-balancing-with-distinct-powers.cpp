class Solution {
public:
    bool balancePan(int a, int b) {
        long long rem = b;
        while (rem > 0) {
            int digit = rem % a;
            if (digit == 0) {
                rem /= a;
            } else if (digit == 1) {
                rem /= a;
            } else if (digit == a - 1) {
                rem = (rem + 1) / a;
            } else {
                return false;
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna