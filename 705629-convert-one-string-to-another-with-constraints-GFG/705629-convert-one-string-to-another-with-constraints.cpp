class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        if (s1.length() != s2.length()) return false;

        string t1 = "", t2 = "";
        for (char c : s1) {
            if (c != '#') t1 += c;
        }
        for (char c : s2) {
            if (c != '#') t2 += c;
        }
        if (t1 != t2) return false;

        int i = 0, j = 0;
        int n = s1.length();

        while (i < n && j < n) {
            while (i < n && s1[i] == '#') i++;
            while (j < n && s2[j] == '#') j++;

            if (i < n && j < n) {
                if (s1[i] != s2[j]) return false;
                if (s1[i] == 'A' && i < j) return false;
                if (s1[i] == 'B' && i > j) return false;
                i++;
                j++;
            }
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna