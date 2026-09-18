class Solution {
private:
    int minDiff = INT_MAX;
    Node* prevNode = nullptr;

    // Helper function for in-order traversal
    void inOrder(Node* root) {
        if (!root) return;

        // 1. Traverse left subtree
        inOrder(root->left);

        // 2. Process current node: calculate absolute difference with previous node
        if (prevNode != nullptr) {
            minDiff = min(minDiff, root->data - prevNode->data);
        }
        
        // Update previous node to current node
        prevNode = root;

        // 3. Traverse right subtree
        inOrder(root->right);
    }

public:
    // Driver function expects 'absDiff'
    int absDiff(Node* root) {
        minDiff = INT_MAX;
        prevNode = nullptr;
        
        inOrder(root);
        
        return minDiff;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna