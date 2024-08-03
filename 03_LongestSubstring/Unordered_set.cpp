
/**
 * 16%, 21% but close enough. Best solution uses hash.
 * Sliding window idea.
 */

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        unordered_set<char> window;

        for (int end = 0; end < s.length(); ++end) {
            char currChar = s[end];

            while (window.find(currChar) != window.end()) {
                window.erase(s[start]);
                ++start;
            }

            window.insert(currChar);

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};