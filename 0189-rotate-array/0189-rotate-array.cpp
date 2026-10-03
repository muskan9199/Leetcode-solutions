class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        int start = 0;
        int end = n - 1;

        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }

        start = 0;
        end = k - 1;

        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }

        start = k;
        end = n - 1;

        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna