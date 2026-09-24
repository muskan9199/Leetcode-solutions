#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();
        if (n == 0) return 0;

        vector<pair<int, int>> discs(n);
        for (int i = 0; i < n; i++) {
            discs[i] = {r[i], h[i]};
        }

        sort(discs.begin(), discs.end());

        vector<int> dp(n);
        int maxHeight = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = discs[i].second; // Base case: only the current disc
            for (int j = 0; j < i; j++) {
                if (discs[j].first < discs[i].first && discs[j].second < discs[i].second) {
                    dp[i] = max(dp[i], dp[j] + discs[i].second);
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna