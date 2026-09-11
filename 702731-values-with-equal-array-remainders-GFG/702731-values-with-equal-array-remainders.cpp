#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int sameMod(std::vector<int>& arr) {
        int min_val = *std::min_element(arr.begin(), arr.end());
        int g = 0;

        for (int x : arr) {
            g = std::gcd(g, x - min_val);
        }

        // If all elements are equal, infinite values of k exist
        if (g == 0) {
            return -1;
        }

        // Count number of divisors of g
        int divisor_count = 0;
        for (int i = 1; i * i <= g; ++i) {
            if (g % i == 0) {
                divisor_count++;
                if (i * i != g) {
                    divisor_count++;
                }
            }
        }

        return divisor_count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna