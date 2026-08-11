// - Given a string s, find the length of the longest without duplicate characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

#include <set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        set<char> bucket;

        
        for (int i = 0; i < s.size(); i++) {
            if (s.isin(s[i])) {
                
            }
            s.insert(s[i])
        }
    }
};