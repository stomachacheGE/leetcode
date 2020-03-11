/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1) return false;
        unordered_map<int, int> table;
        for (int i=0; i<nums.size(); i++) {
            if (table.find(nums[i]) != table.end()) {
                if (i - table[nums[i]] <= k) return true;
            }
            table[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

