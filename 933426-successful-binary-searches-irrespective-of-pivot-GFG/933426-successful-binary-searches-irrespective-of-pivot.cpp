class Solution {
public:
    int countAlwaysFound(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax(n), rightMin(n);

        leftMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }

        rightMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], arr[i]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if ((i == 0 || arr[i] >= leftMax[i - 1]) && (i == n - 1 || arr[i] <= rightMin[i + 1])) {
                count++;
            }
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna