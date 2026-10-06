class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        vector<int> ans;

        while(i < n && j < m) {
            if(a[i] < b[j]) {
                if(ans.empty() || a[i] != ans.back()) {
                    ans.push_back(a[i]);
                }
                i++;
            }
            else if(a[i] > b[j]) {
                if(ans.empty() || b[j] != ans.back()) {
                    ans.push_back(b[j]);
                }
                j++;
            }
            else {
                if(ans.empty() || a[i] != ans.back()) {
                    ans.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        while(i < n) {
            if(a[i] != ans.back()) {
                ans.push_back(a[i]);
            }
            i++;
        }

        while(j < m) {
            if(b[j] != ans.back()) {
                ans.push_back(b[j]);
            }
            j++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna