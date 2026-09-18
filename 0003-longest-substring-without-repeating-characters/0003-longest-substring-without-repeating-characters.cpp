class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> hash(256 , -1);
        int r=0;
        int l = 0;
        int len =0;
        int  maxLen = 0;
        while(r<n){
            if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] +1;
            }
            }
            len = r-l+1;
            maxLen = max(len , maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna