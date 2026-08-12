class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int zeroes = 0;
        int len = 0;
        int maxlen = 0;

        while(r < n) {
            if(nums[r] == 0) {
                zeroes++;
            }

            while(zeroes > k) {

                if(nums[l] == 0) {
                    zeroes--;
                }

                l++;
            }
            len = r - l + 1;
            maxlen = max(len, maxlen);

            r++;
        }

        return maxlen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna