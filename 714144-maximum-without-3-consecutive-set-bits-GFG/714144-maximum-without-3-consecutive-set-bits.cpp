class Solution {
public:
    int maxValue(int n) {
        for (int i = 29; i >= 0; --i) {
            if ((n & (1 << i)) && (n & (1 << (i - 1))) && (n & (1 << (i - 2)))) {
                n ^= (1 << (i - 2));
            }
        }
        return n;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna