/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // solution one
        if (nums.size() <= 1) return;
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                j++;
                continue;
            }
            nums[i] = nums[j];
            i++;
            j++;
        }
        while (i < nums.size()) {
            nums[i++] = 0;
        }
        
    }
};
// @lc code=end

