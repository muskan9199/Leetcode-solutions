class Solution {
private:
    int countSearchable(vector<int>& arr, int l, int r, int max_allowed_left, int min_allowed_right) {
        if (l > r) return 0;

        int mid = l + (r - l) / 2;
        int count = 0;

        if (arr[mid] > max_allowed_left && arr[mid] < min_allowed_right) {
            count = 1;
        }

        int left_searchable = countSearchable(arr, l, mid - 1, max_allowed_left, min(min_allowed_right, arr[mid]));
        int right_searchable = countSearchable(arr, mid + 1, r, max(max_allowed_left, arr[mid]), min_allowed_right);

        return count + left_searchable + right_searchable;
    }

public:
    int binarySearchable(vector<int>& arr) {
        return countSearchable(arr, 0, arr.size() - 1, INT_MIN, INT_MAX);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna