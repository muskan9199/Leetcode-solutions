class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        int current_sum = 0;

        for (int i = 0; i < m; i++) {
            current_sum += arr[i];
        }

        int max_sum = current_sum;

        for (int i = 1; i < n; i++) {
            current_sum = current_sum - arr[i - 1] + arr[(i + m - 1) % n];
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna