class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if (found != string::npos) {
            return static_cast<int>(found);
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna