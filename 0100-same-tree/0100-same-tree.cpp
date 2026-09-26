class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, trees are identical up to this point
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one node is null and the other is not, structural difference found
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If node values differ, trees are not the same
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna