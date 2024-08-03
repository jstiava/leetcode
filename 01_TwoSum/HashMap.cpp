#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            hashMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int remaining = target - nums[i];
            if (hashMap.contains(remaining)) {
                int found = hashMap.at(remaining);
                if (i != found) {
                    return {i, found};
                }
            }
        }

        return {-1, -1};
    }
};