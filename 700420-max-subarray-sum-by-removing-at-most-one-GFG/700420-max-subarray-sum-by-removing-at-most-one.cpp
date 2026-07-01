class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        vector<int> max_forward(n);
        int current_max = arr[0];
        int overall_max = arr[0];
        max_forward[0] = arr[0];

        for (int i = 1; i < n; i++) {
            current_max = max(arr[i], current_max + arr[i]);
            max_forward[i] = current_max;
            overall_max = max(overall_max, current_max);
        }

        vector<int> max_backward(n);
        current_max = arr[n - 1];
        max_backward[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            current_max = max(arr[i], current_max + arr[i]);
            max_backward[i] = current_max;
        }

        for (int i = 1; i < n - 1; i++) {
            overall_max = max(overall_max, max_forward[i - 1] + max_backward[i + 1]);
        }

        return overall_max;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna