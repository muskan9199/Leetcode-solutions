class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }

        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int r = q[0];
            int c = q[1];

            if (mat[r][c] > k) {
                ans.push_back(-1);
                continue;
            }

            int maxExt = min({r, n - 1 - r, c, m - 1 - c});
            int low = 0, high = maxExt, best = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int r1 = r - mid, c1 = c - mid;
                int r2 = r + mid, c2 = c + mid;

                if (getSum(r1, c1, r2, c2) <= k) {
                    best = 2 * mid + 1;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna