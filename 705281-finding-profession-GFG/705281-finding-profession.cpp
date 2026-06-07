class Solution {
public:
    string profession(int level, int pos) {
        bool isEngineer = true;

        while (pos > 1) {
            if (pos % 2 == 0) {
                isEngineer = !isEngineer;
            }
            pos = (pos + 1) / 2;
        }

        return isEngineer ? "Engineer" : "Doctor";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna