class Solution {
public:
    void backtrack(int current_digit, int current_num, int n, vector<int>& result) {
        if (n == 0) {
            result.push_back(current_num);
            return;
        }

        for (int i = current_digit + 1; i <= 9; ++i) {
            backtrack(i, current_num * 10 + i, n - 1, result);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> result;
        if (n == 1) {
            for (int i = 0; i <= 9; ++i) {
                result.push_back(i);
            }
            return result;
        }
        
        for (int i = 1; i <= 9; ++i) {
            backtrack(i, i, n - 1, result);
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna