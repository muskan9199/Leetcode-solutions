#include <string>
#include <algorithm>

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the required sum is greater than the maximum possible sum with 'num' 9s, 
        // or less than what is needed (at least 1 per digit to form a positive number/valid digits), it's impossible.
        if (sum > (long long)num * 9 || sum < 1) {
            return "";
        }
        
        string result = "";
        for (int i = 0; i < num; ++i) {
            // Greedily take the maximum possible digit for the current position
            int digit = min(9, sum);
            result += to_string(digit);
            sum -= digit;
        }
        
        // If there's still remaining sum after filling all digits, it's invalid.
        if (sum > 0) {
            return "";
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna