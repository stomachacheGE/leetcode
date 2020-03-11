/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        unordered_set<int> set;
        for (auto &num : nums) {
            if (set.find(num) != set.end()) return true;
            set.insert(num);
        }
        return false;
    }
};
// @lc code=end

