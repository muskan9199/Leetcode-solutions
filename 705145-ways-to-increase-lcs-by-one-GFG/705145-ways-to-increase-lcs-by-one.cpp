#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        vector<vector<int>> dp1(n1 + 2, vector<int>(n2 + 2, 0));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp1[i][j] = dp1[i - 1][j - 1] + 1;
                } else {
                    dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
                }
            }
        }

        int original_lcs = dp1[n1][n2];

        vector<vector<int>> dp2(n1 + 2, vector<int>(n2 + 2, 0));
        for (int i = n1; i >= 1; i--) {
            for (int j = n2; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp2[i][j] = dp2[i + 1][j + 1] + 1;
                } else {
                    dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i <= n1; i++) {
            vector<bool> visited(26, false);

            for (int j = 0; j < n2; j++) {
                char c = s2[j];
                if (!visited[c - 'a']) {
                   
                    if (dp1[i][j] + 1 + dp2[i + 1][j + 2] == original_lcs + 1) {
                        ans++;
                        visited[c - 'a'] = true;
                    }
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna