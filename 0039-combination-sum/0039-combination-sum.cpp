class Solution {
public:

    vector<vector<int>> ans;

    void helper(vector<int>& candidates,
                int index,
                int target,
                int sum,
                vector<int>& path) {

        if(sum == target) {
            ans.push_back(path);
            return;
        }

        if(sum > target || index >= candidates.size()) {
            return;
        }

        path.push_back(candidates[index]);

        helper(candidates,
               index,
               target,
               sum + candidates[index],
               path);
        path.pop_back();
        helper(candidates,
               index + 1,
               target,
               sum,
               path);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates ,int target) {

        vector<int> path;

        helper(candidates, 0, target, 0, path);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna