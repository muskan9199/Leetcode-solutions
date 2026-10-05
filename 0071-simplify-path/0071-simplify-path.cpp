class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string dir;
        stringstream ss(path);
        
        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                continue;
            }
            if (dir == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(dir);
            }
        }
        
        string result = "";
        for (const string& s : st) {
            result += "/" + s;
        }
        
        return result.empty() ? "/" : result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna