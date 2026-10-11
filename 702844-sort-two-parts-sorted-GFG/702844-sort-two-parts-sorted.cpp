class Solution {
public:
    void mergeTwoParts(vector<int>& arr) {
        int n = arr.size();
        int breakPoint = -1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                breakPoint = i + 1;
                break;
            }
        }
        if (breakPoint == -1) return;

        vector<int> temp(n);
        int i = 0, j = breakPoint, k = 0;

        while (i < breakPoint && j < n) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i < breakPoint) {
            temp[k++] = arr[i++];
        }

        while (j < n) {
            temp[k++] = arr[j++];
        }

        for (int idx = 0; idx < n; idx++) {
            arr[idx] = temp[idx];
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna