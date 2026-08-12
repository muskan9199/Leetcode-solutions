class Solution {
  public:
    int maxOnes(vector<int>& arr, int k){
        int n = arr.size();
        int l = 0;
        int r = 0;
        int zeroes = 0;
        int len = 0;
        int maxlen = 0;

        while(r < n) {

            if(arr[r] == 0) {
                zeroes++;
            }

            while(zeroes > k) {

                if(arr[l] == 0) {
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