class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        vector<int> left(n), right(n);

        left[0] = min(arr[0], 1);
        for (int i = 1; i < n; ++i) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }

        right[n - 1] = min(arr[n - 1], 1);
        for (int i = n - 2; i >= 0; --i) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }

        long long maxPyramidSum = 0;
        for (int i = 0; i < n; ++i) {
            long long peak = min(left[i], right[i]);
            long long currentPyramidSum = peak * peak;
            maxPyramidSum = max(maxPyramidSum, currentPyramidSum);
        }

        return totalSum - maxPyramidSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna