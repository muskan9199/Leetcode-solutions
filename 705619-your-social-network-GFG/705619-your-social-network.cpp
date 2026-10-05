class Solution {
public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        vector<vector<int>> result;
        int n = arr.size() + 1;

        for (int i = 2; i <= n; ++i) {
            int current = i;
            int dist = 0;
            vector<vector<int>> temp;

            while (current > 1) {
                current = arr[current - 2];
                dist++;
                temp.push_back({i, current, dist});
            }

            for (int k = temp.size() - 1; k >= 0; --k) {
                result.push_back(temp[k]);
            }
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna