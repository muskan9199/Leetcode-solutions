class Solution {
public:
    vector<int> constructList(vector<vector<int>>& queries) {
        vector<int> ans;
        int cum_xor = 0;
        
        for (int i = queries.size() - 1; i >= 0; --i) {
            if (queries[i][0] == 0) {
                ans.push_back(queries[i][1] ^ cum_xor);
            } else {
                cum_xor ^= queries[i][1];
            }
        }
        
        ans.push_back(0 ^ cum_xor);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna