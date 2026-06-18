class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int totalCoverage = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    for (int k = i - 1; k >= 0; k--) {
                        if (mat[k][j] == 1) {
                            totalCoverage++;
                            break;
                        }
                    }
                    for (int k = i + 1; k < n; k++) {
                        if (mat[k][j] == 1) {
                            totalCoverage++;
                            break;
                        }
                    }
                    for (int k = j - 1; k >= 0; k--) {
                        if (mat[i][k] == 1) {
                            totalCoverage++;
                            break;
                        }
                    }
                    for (int k = j + 1; k < m; k++) {
                        if (mat[i][k] == 1) {
                            totalCoverage++;
                            break;
                        }
                    }
                }
            }
        }
        return totalCoverage;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna