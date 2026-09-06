class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        long long totalSum = 0;
        int n = arr.size();

        for (int bit = 0; bit < 32; bit++) {
            long long count = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] & (1 << bit)) {
                    count++;
                }
            }
            totalSum += count * (count - 1) / 2 * (1LL << bit);
        }

        return totalSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna