class Solution {
public:
    vector<int> getMarks(vector<int>& l, vector<int>& r, vector<int>& rank) {
        int n = l.size();
        vector<long long> pref(n);
        long long current_total = 0;

        for (int i = 0; i < n; i++) {
            current_total += (r[i] - l[i] + 1);
            pref[i] = current_total;
        }

        vector<int> ans;
        ans.reserve(rank.size());

        for (int k : rank) {
            int low = 0, high = n - 1;
            int idx = n - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (pref[mid] >= k) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            long long prev_count = (idx > 0) ? pref[idx - 1] : 0;
            long long offset = k - prev_count - 1;
            ans.push_back(l[idx] + offset);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna