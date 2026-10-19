class Solution {
public:
    int goodIndices(vector<int>& arr) {
        int n = arr.size();
        vector<int> status(n, 0); 
        int goodCount = 0;

        for (int i = 0; i < n; ++i) {
            if (status[i] != 0) {
                if (status[i] == 1) goodCount++;
                continue;
            }

            int curr = i;
            vector<int> path;

            while (status[curr] == 0) {
                status[curr] = -2; 
                path.push_back(curr);

                long long nextIdx = (long long)curr + arr[curr];

                if (nextIdx < 0 || nextIdx >= n) {
                    for (int idx : path) {
                        status[idx] = 1;
                    }
                    goodCount++;
                    break;
                }

                if (status[nextIdx] == 1) {
                    for (int idx : path) {
                        status[idx] = 1;
                    }
                    goodCount++;
                    break;
                }

                if (status[nextIdx] == -1 || status[nextIdx] == -2) {
                    for (int idx : path) {
                        status[idx] = -1;
                    }
                    break;
                }

                curr = nextIdx;
            }

            if (status[i] == 1) {
                // Already counted when path was marked
            }
        }

        return goodCount;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna