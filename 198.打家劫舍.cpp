/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int fn_1 = nums[0], fn_2 = 0, temp;
        for (int i=1; i<nums.size(); i++) {
            
            // if (fn_2 + nums[i] > fn_1) {
            //     temp = fn_1;
            //     fn_1 = fn_2 + nums[i];
            //     fn_2 = temp;
            // } else {
            //     fn_2 = fn_1;
            // }
            //以下更简洁
            temp = fn_1;
            fn_1 = max(fn_1, fn_2 + nums[i]);
            fn_2 = temp;
        }
        return fn_1;
    }
};
// @lc code=end

