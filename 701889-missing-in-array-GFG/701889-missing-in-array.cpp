class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = arr.size() + 1;
        long long expectedSum = n * (n + 1) / 2;
        long long actualSum = 0;

        for (int num : arr) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna