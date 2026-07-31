class Solution {
  public:
    int maxWater(vector<int> &arr) {
      int n = arr.size();
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        lmax[0] = arr[0];
        rmax[n-1] = arr[n-1];
        
        for(int i=1; i<n; i++){
            lmax[i] = max(lmax[i-1] , arr[i]);
        }
        for(int i=n-2; i>=0; i--){
            rmax[i] = max(rmax[i+1] , arr[i]);
        }

        int ans =0;
        for(int i=0; i<n; i++){
             ans += min(lmax[i] ,rmax[i]) - arr[i];

        }
       
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna