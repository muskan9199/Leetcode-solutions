class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int candidate = 0;
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(count == 0) {
                candidate = arr[i];
            }

            if(candidate == arr[i]) {
                count++;
            }
            else {
                count--;
            }
        }

        int freq = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] == candidate) {
                freq++;
            }
        }

        if(freq > n/2) {
            return candidate;
        }
        else {
            return -1;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna