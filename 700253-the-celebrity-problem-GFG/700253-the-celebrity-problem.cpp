class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0;
        int down = n - 1;

        while(top < down) {
            if(mat[top][down] == 1) {
                top++;
            }
            else {
                down--;
            }
        }
        int candidate = top;

        for(int i = 0; i < n; i++) {
            if(i != candidate && mat[candidate][i] == 1) {
                return -1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(i != candidate && mat[i][candidate] == 0) {
                return -1;
            }
        }
        return candidate;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna