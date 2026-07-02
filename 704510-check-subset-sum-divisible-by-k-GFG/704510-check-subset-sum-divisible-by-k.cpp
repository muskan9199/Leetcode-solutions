class Solution {
public:
    bool divisibleByK(vector<int>& arr, int k) {
        int n = arr.size();
        
        // If the number of elements is greater than or equal to k,
        // by the Pigeonhole Principle, there must exist a subset divisible by k.
        if (n >= k) return true;
        
        // dp[i] will be true if a subset sum with remainder i is possible
        vector<bool> dp(k, false);
        
        for (int i = 0; i < n; i++) {
            // Find the remainder of the current element
            int rem = arr[i] % k;
            
            // If the element itself is divisible by k, we found our subset
            if (rem == 0) return true;
            
            // To store new remainders formed in this step
            vector<bool> temp(k, false);
            
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    // If remainder 'r' was possible, then (r + rem) % k is also possible
                    int next_rem = (r + rem) % k;
                    if (next_rem == 0) return true; // Found a valid subset sum
                    temp[next_rem] = true;
                }
            }
            
            // Update the main DP table with new remainders
            for (int r = 0; r < k; r++) {
                if (temp[r]) dp[r] = true;
            }
            
            // Also mark the remainder of the single element itself as possible
            dp[rem] = true;
        }
        
        return dp[0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna