class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
      int n = arr.size();
      int largest = INT_MIN;
      int slargest = INT_MIN;
      for(int i=0; i<n; i++){
        if(arr[i] > largest ){
            slargest = largest;
            largest = arr[i];
        }else{
            if(arr[i] > slargest && arr[i] != largest ){
                slargest = arr[i];
            }
        }
      }
      if(slargest == INT_MIN){
         return -1;
     }else{
         return slargest;
     }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna