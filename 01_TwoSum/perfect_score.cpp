class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        int score = 0;
        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            int diff = target - value;
            auto it = hashmap.find(diff);
            if (it != hashmap.end()) {
                int secondIndex = hashmap.at(diff);
                return {i, secondIndex};
            }

            hashmap.insert({value, i});
        }

        return {};
    }

};