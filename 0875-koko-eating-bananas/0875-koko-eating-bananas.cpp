class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while( low <= high){
            int mid = (low + high)/2;
            long long  hours = 0;
            for( int i=0; i<piles.size(); i++){
                hours += ceil((double)piles[i]/mid);
            }
            if( hours <= h){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna