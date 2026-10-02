class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        int n = arr.size();
         int count = 1;
         int maxCount=1;
        for( int i=1;i<arr.size(); i++){
            if(arr[i] == arr[i-1]){
                count ++;
                maxCount = max(maxCount, count);
            }
            else{
            count = 1;
        }
        }
        return maxCount;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna