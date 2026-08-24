class Solution {
public:
    int countValidPrefixes(string s) {
        int count0 = 0, count1 = 0;
        int validCount = 0;

        for (char c : s) {
            if (c == '0') {
                count0++;
            } else {
                count1++;
            }

            if (abs(count0 - count1) <= 1) {
                validCount++;
            }
        }

        return validCount;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna