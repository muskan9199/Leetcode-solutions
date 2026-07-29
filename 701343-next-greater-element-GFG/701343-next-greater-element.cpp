class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
           int n = arr.size();
        stack<int> st;
       vector<int> nge(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() <=arr[i]){
                st.pop();
            }
          if(st.empty()){
            nge[i]=-1;
          }
          else{
            nge[i] = st.top();
          }
            st.push(arr[i]);
        }
       return nge;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna