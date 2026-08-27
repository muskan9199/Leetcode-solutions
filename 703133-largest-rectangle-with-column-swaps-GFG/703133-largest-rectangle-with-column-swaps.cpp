class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> hist(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            hist[0][j] = mat[0][j];
            for (int i = 1; i < n; ++i) {
                if (mat[i][j] == 1) {
                    hist[i][j] = hist[i - 1][j] + 1;
                } else {
                    hist[i][j] = 0;
                }
            }
        }

        int max_area = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> count(n + 1, 0);
            for (int j = 0; j < m; ++j) {
                count[hist[i][j]]++;
            }

            int col_count = 0;
            for (int h = n; h >= 0; --h) {
                col_count += count[h];
                max_area = max(max_area, col_count * h);
            }
        }

        return max_area;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna