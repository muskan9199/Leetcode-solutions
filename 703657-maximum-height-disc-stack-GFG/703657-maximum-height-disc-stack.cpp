#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static const int MAX_H = 1000;
    int bit[MAX_H + 1];

    void update(int idx, int val) {
        for (; idx <= MAX_H; idx += idx & -idx) {
            bit[idx] = max(bit[idx], val);
        }
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res = max(res, bit[idx]);
        }
        return res;
    }

public:
    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();
        if (n == 0) return 0;

        // Reset Fenwick Tree array
        fill(bit, bit + MAX_H + 1, 0);

        // Store disc dimensions
        vector<pair<int, int>> discs(n);
        for (int i = 0; i < n; i++) {
            discs[i] = {r[i], h[i]};
        }

        // Sort primarily by radius in ascending order
        sort(discs.begin(), discs.end());

        int ans = 0;
        int i = 0;

        // Process discs group-by-group for each unique radius
        while (i < n) {
            int j = i;
            while (j < n && discs[j].first == discs[i].first) {
                j++;
            }

            // Step 1: Query maximum valid stack height for all discs with current radius
            vector<int> currentDP(j - i);
            for (int k = i; k < j; k++) {
                int height = discs[k].second;
                int bestPrev = query(height - 1);
                currentDP[k - i] = bestPrev + height;
                ans = max(ans, currentDP[k - i]);
            }

            for (int k = i; k < j; k++) {
                update(discs[k].second, currentDP[k - i]);
            }

            i = j;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna