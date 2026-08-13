class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> hash(n, 0);

        int l = 0;
        int r = 0;
        int maxLen = 0;
        int distinct = 0;

        while(r < n) {
            if(hash[fruits[r]] == 0) {
                distinct++;
            }

            hash[fruits[r]]++;

            while(distinct > 2) {

                hash[fruits[l]]--;

                if(hash[fruits[l]] == 0) {
                    distinct--;
                }

                l++;
            }
            maxLen = max(maxLen, r - l + 1);

            r++;
        }
        return maxLen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna