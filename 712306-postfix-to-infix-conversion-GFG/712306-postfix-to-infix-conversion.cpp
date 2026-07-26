class Solution {
  public:
    string postToInfix(string &exp) {
        stack<string> st;

        for(int i = 0; i < exp.length(); i++) {
            char ch = exp[i];

            if((ch >= 'A' && ch <= 'Z') ||
               (ch >= 'a' && ch <= 'z') ||
               (ch >= '0' && ch <= '9')) {
                st.push(string(1, ch));
            }
            else {
                string t1 = st.top();
                st.pop();

                string t2 = st.top();
                st.pop();

                string conS = "(" + t2 + string(1, ch) + t1 + ")";

                st.push(conS);
            }
        }

        return st.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna