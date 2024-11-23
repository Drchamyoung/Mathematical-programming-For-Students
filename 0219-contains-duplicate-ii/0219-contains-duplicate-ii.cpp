class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indexMap; // Map to store the most recent index of each element

        for (int i = 0; i < nums.size(); ++i) {
            // Check if nums[i] is in the map and if the indices difference is <= k
            if (indexMap.find(nums[i]) != indexMap.end() && i - indexMap[nums[i]] <= k) {
                return true;
            }
            // Update the current index of nums[i] in the map
            indexMap[nums[i]] = i;
        }

        return false; // No such pair found
    }
};
