class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 1;
        
        // Helper lambda function to expand around a given center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int currentLength = right - left + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    start = left;
                }
                left--;
                right++;
            }
        };
        
        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindromes (e.g., "aba", center is 'b')
            expandAroundCenter(i, i);
            
            // Case 2: Even length palindromes (e.g., "abba", center is between 'b' and 'b')
            expandAroundCenter(i, i + 1);
        }
        
        return s.substr(start, maxLength);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna