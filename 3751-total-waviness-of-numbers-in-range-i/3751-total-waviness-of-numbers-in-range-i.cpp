class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int totalSum = 0;
        for (int i = num1; i <= num2; i++) {
            totalSum += calculateWaviness(i);
        }
        return totalSum;
    }

private:
    int calculateWaviness(int num) {
        if (num < 100) {
            return 0;
        }
        
        string s = to_string(num);
        int waviness = 0;
        int n = s.length();
        
        for (int i = 1; i < n - 1; i++) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) || 
                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                waviness++;
            }
        }
        
        return waviness;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna