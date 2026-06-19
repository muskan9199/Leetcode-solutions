class Solution {
public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        vector<long long> pref(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }
        
        for (int i = 0; i < n; i++) {
            int m = i / 2;
            long long right_sum = pref[i + 1] - pref[m + 1];
            long long left_sum = (i % 2 == 1) ? pref[m + 1] : pref[m];
            ans[i] = right_sum - left_sum;
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna