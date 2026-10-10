#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        if (s.length() < totalLen) return result;

        std::unordered_map<std::string, int> wordMap;
        for (const std::string& word : words) {
            wordMap[word]++;
        }

        // Iterate through each possible offset up to wordLen
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            std::unordered_map<std::string, int> seenMap;
            int count = 0;

            while (right + wordLen <= s.length()) {
                std::string sub = s.substr(right, wordLen);
                right += wordLen;

                // Check if the word is valid
                if (wordMap.find(sub) != wordMap.end()) {
                    seenMap[sub]++;
                    count++;

                    // If word frequency exceeds the required count, shrink from the left
                    while (seenMap[sub] > wordMap[sub]) {
                        std::string leftSub = s.substr(left, wordLen);
                        seenMap[leftSub]--;
                        left += wordLen;
                        count--;
                    }

                    // If we matched all words, record the starting index
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Reset if the word is not in words array
                    seenMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna