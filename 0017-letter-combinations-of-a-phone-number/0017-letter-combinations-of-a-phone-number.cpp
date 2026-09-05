class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> pad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        string current;

        auto backtrack = [&](auto& self, int index) -> void {
            if (index == digits.length()) {
                result.push_back(current);
                return;
            }

            string letters = pad[digits[index] - '0'];
            for (char c : letters) {
                current.push_back(c);
                self(self, index + 1);
                current.pop_back();
            }
        };

        backtrack(backtrack, 0);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna