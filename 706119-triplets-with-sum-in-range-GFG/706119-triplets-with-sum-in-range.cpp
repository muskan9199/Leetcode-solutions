#include <vector>
#include <algorithm>

class Solution {
private:
    int countTripletsLessThanOrEqual(std::vector<int>& arr, int target) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum <= target) {
                    count += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }
        return count;
    }

public:
    int countTriplets(std::vector<int>& arr, int l, int r) {
        std::sort(arr.begin(), arr.end());
        return countTripletsLessThanOrEqual(arr, r) - countTripletsLessThanOrEqual(arr, l - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna