class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int maxi = INT_MIN;
        for( int i =0; i<n; i++){
            sum+= nums[i];
            if(sum > maxi){
                maxi = sum;
            }
             if ( sum <0){
                sum = 0;
            }
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna