class Solution {
public:
    int maxPeopleDefeated(int p) {
        long long low = 1, high = 1000; 
        long long ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sum = (mid * (mid + 1) * (2 * mid + 1)) / 6;
            
            if (sum <= p) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna