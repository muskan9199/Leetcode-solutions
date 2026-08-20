class Solution {
  private:
    int solve(Node* root, int &ans) {
        if (!root) return INT_MAX;

        if (!root->left && !root->right) return root->data;

        int leftMin = solve(root->left, ans);
        int rightMin = solve(root->right, ans);

        int minChild = std::min(leftMin, rightMin);

        ans = std::max(ans, root->data - minChild);

        return std::min(minChild, root->data);
    }

  public:
    int maxDiff(Node* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna