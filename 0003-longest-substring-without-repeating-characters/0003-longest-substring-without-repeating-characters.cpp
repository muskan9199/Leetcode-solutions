class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int r = 0;
        int l = 0;
        int len = 0;
        int maxlen = 0;

        vector<int> hash(256, -1);

        while(r < n) {

            if(hash[s[r]] != -1) {
                if(hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            len = r - l + 1;
            maxlen = max(len, maxlen);

            hash[s[r]] = r;

            r++;
        }

        return maxlen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna