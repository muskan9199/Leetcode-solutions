class Solution {
public:
    int solve(int n, string s) {
        vector<int> status(26, 0);
        int occupied = 0;
        int unassignedCount = 0;

        for (char ch : s) {
            int idx = ch - 'A';

            if (status[idx] == 0) {
                if (occupied < n) {
                    status[idx] = 1;
                    occupied++;
                } else {
                    status[idx] = 2;
                    unassignedCount++;
                }
            } else if (status[idx] == 1) {
                status[idx] = 0;
                occupied--;
            }
        }

        return unassignedCount;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna