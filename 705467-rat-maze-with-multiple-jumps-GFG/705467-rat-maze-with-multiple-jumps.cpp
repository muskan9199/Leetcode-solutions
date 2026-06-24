class Solution {
private:
    bool solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& ans, vector<vector<int>>& memo, int n) {
        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        if (memo[i][j] == 0) {
            return false;
        }

        ans[i][j] = 1;
        int maxJumps = mat[i][j];

        for (int k = 1; k <= maxJumps; ++k) {
            if (j + k < n) {
                if (solve(i, j + k, mat, ans, memo, n)) {
                    return true;
                }
            }
            if (i + k < n) {
                if (solve(i + k, j, mat, ans, memo, n)) {
                    return true;
                }
            }
        }

        ans[i][j] = 0;
        memo[i][j] = 0;
        return false;
    }

public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> memo(n, vector<int>(n, -1));

        if (solve(0, 0, mat, ans, memo, n)) {
            return ans;
        }

        return {{-1}};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna