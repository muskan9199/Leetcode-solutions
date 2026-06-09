class Solution {
public:
    bool canSeatAllPeople(int k, vector<int>& seats) {
        int n = seats.size();
        
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (i > 0 && seats[i - 1] == 1) return false;
                if (i < n - 1 && seats[i + 1] == 1) return false;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (k == 0) return true;
            
            if (seats[i] == 0) {
                bool prev_empty = (i == 0 || seats[i - 1] == 0);
                bool next_empty = (i == n - 1 || seats[i + 1] == 0);
                
                if (prev_empty && next_empty) {
                    seats[i] = 1;
                    k--;
                }
            }
        }
        
        return k <= 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna