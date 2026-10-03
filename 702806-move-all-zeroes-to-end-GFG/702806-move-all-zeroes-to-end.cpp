class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int j = 0;
        for(int i=0; i<n; i++){
            if(arr[i] !=0){
                swap(arr[i] , arr[j]);
                j++;
            }
        }

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna