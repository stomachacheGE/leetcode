/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            while (right > 0 && right < nums.size() && nums[right] == nums[right-1]) {
                right++;
            }
            if (right == nums.size()) break;
            nums[left] = nums[right];
            left++;
            right++;
        }
        return left;
    }
};
// @lc code=end

