class Solution {
public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int r = 0, c = 0;
        int dir = 0; 
        
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        int last_r = 0, last_c = 0;
        
        while (r >= 0 && r < n && c >= 0 && c < m) {
            last_r = r;
            last_c = c;
            
            if (mat[r][c] == 1) {
                mat[r][c] = 0;
                dir = (dir + 1) % 4;
            }
            
            r += dr[dir];
            c += dc[dir];
        }
        
        return {last_r, last_c};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna