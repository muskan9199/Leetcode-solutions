class Solution {
public:
    string lexicographicallySmallest(string &s, int k) {
        int n = s.length();
        
        if ((n & (n - 1)) == 0) {
            k /= 2;
        } else {
            k *= 2;
        }
        
        if (k >= n) return "-1";
        if (k <= 0) return s;
        
        string result = "";
        
        for (char ch : s) {
            while (!result.empty() && result.back() > ch && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(ch);
        }
        
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        
        return result.empty() ? "-1" : result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna