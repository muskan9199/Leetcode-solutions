class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> S;
        S.push_back(s);
        long long current_sum = s;

        for (int val : arr) {
            long long next_val = current_sum + val;
            S.push_back(next_val);
            current_sum += next_val;
            if (next_val > x) {
                break;
            }
        }

        for (int i = S.size() - 1; i >= 0; i--) {
            if (x >= S[i]) {
                x -= S[i];
            }
        }

        return x == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna