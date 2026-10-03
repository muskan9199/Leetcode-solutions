class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        int n = arr.size();
        if(n==0){
        return{};
        }
        int i=0;
        for( int j=1; j<n; j++){
            if(arr[i]!=arr[j]){
                i++;
                arr[i] = arr[j];
            }
        }
       arr.resize(i+1);
       return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna