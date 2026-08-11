class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        int score = 0;
        unordered_map<int, int> hashmap;
        
        int half_count = 0;
        vector<int> half_indeces;
        int half_value = target % 2 == 0 ? target / 2 : 0;

        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            if (value == half_value && half_value != 0) {
                half_count += 1;
                half_indeces.push_back(i);
            }
            hashmap.insert({value, i});
        }
        
        if (half_count == 2) {
            return half_indeces;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            auto it = hashmap.find(diff);
            if (it != hashmap.end()) {
                int secondIndex = hashmap.at(diff);
                if (secondIndex != i) {
                    return {i, secondIndex};
                }
            }
        }

        return {};
    }

};