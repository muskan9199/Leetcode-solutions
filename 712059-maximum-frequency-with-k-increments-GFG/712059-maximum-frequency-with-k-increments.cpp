class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        long long currentSum = 0;
        int left = 0;
        int maxFreq = 0;

        for (int right = 0; right < arr.size(); ++right) {
            currentSum += arr[right];

            while ((long long)arr[right] * (right - left + 1) - currentSum > k) {
                currentSum -= arr[left];
                left++;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna