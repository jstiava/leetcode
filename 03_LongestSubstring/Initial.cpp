#include "unordered_map"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> substring;
        int max = 0;
        int start = 0;
        int i = 0;

        while (true) {
            if (i >= s.size()) {
                return max;
            }
            else if (substring.contains(s[i])) {
                max = substring.size() > max ? substring.size() : max;

                int toLastOccurance = substring[s[i]] + 1;
                substring.clear();
                i = toLastOccurance;

                if (s.size() - i <= max) {
                    return max;
                }
            }    
            else {
                substring[s[i]] = i;
                ++i;
            }
        }
    }
};