class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        int leader = arr[n-1];
        vector<int> ans;
        ans.push_back(arr[n-1]);
        for(int i=n-2; i>=0; i--){
         if(arr[i] >= leader){
            leader = arr[i];
           ans.push_back(arr[i]);
         }
        }
        reverse(ans.begin() , ans.end());
      return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna