class Solution {
public:
    string chooseSwap(string& s) {
        set<char> available_chars;
        for (char c : s) {
            available_chars.insert(c);
        }

        for (int i = 0; i < s.length(); i++) {
            available_chars.erase(s[i]);
            if (available_chars.empty()) {
                break;
            }

            char smallest_available = *available_chars.begin();
            if (smallest_available < s[i]) {
                char char1 = s[i];
                char char2 = smallest_available;
                for (int j = 0; j < s.length(); j++) {
                    if (s[j] == char1) {
                        s[j] = char2;
                    } else if (s[j] == char2) {
                        s[j] = char1;
                    }
                }
                break;
            }
        }
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna