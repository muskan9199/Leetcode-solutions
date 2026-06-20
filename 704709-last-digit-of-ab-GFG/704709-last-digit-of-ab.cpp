class Solution {
public:
    int getLastDigit(string &a, string &b) {
        if (b == "0") return 1;
        if (a == "0") return 0;

        int base = a.back() - '0';

        int exp = 0;
        for (char c : b) {
            exp = (exp * 10 + (c - '0')) % 4;
        }

        if (exp == 0) exp = 4;

        int result = pow(base, exp);
        return result % 10;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna