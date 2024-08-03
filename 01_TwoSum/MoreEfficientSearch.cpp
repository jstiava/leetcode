#include <vector>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) {
                    continue;
                }

                int sum = nums[i] + nums[j];
                if (sum > target) {
                    i=+1;
                }
                else if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};