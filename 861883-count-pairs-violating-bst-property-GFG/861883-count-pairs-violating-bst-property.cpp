class Solution {
  private:
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    long long merge(vector<int>& arr, int temp[], int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        long long invCount = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                invCount += (mid - i + 1);
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];
        for (i = left; i <= right; i++) arr[i] = temp[i];

        return invCount;
    }

    long long mergeSort(vector<int>& arr, int temp[], int left, int right) {
        long long invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            invCount += mergeSort(arr, temp, left, mid);
            invCount += mergeSort(arr, temp, mid + 1, right);
            invCount += merge(arr, temp, left, mid, right);
        }
        return invCount;
    }

  public:
    int pairsViolatingBST(Node* root) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        vector<int> temp(n);
        return mergeSort(arr, temp.data(), 0, n - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna