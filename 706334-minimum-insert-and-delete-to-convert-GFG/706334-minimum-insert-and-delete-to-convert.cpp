class Solution {
public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        
        unordered_map<int, int> b_indices;
        for (int i = 0; i < m; i++) {
            b_indices[b[i]] = i;
        }
        
        vector<int> filtered_a;
        for (int x : a) {
            if (b_indices.find(x) != b_indices.end()) {
                filtered_a.push_back(b_indices[x]);
            }
        }
        
        vector<int> lis;
        for (int x : filtered_a) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) {
                lis.push_back(x);
            } else {
                *it = x;
            }
        }
        
        return n + m - 2 * lis.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna