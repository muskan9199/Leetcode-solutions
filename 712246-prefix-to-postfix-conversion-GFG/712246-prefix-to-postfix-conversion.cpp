class Solution {
  public:
    string preToPost(string &s) {
            stack<string> st;

        for(int i = s.length()-1; i >= 0; i--) {
            char ch = s[i];
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

                string convS = t1 + t2 + string(1, ch);
                st.push(convS);
            }
        }
        return st.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna