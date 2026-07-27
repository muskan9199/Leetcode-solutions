class Solution {
  public:
    string postToPre(string s) {
       stack<string> st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(isalnum(ch)){
                st.push(string(1,ch));
            }else{
                string t1 = st.top();
                st.pop();
                
                string t2 = st.top();
                st.pop();
                string convS = string(1 , ch) + t2 + t1;
                st.push(convS);
            }
        }
        return st.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna