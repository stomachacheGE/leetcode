/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
private:
    int rob_range(vector<int>& nums, int start, int end) {
        
        if (start > end) return 0;
        if (start == end) return nums[start];
        int fn_1 = 0, fn_2 = 0, fn = 0;
        for (int i=start; i<=end; i++) {
            fn = max(fn_1, fn_2 + nums[i]);
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
public:
    int rob(vector<int>& nums) {

        // solution one
        // 太复杂不能通过全部case
        // if (nums.empty()) return 0;
        // if (nums.size() == 1) return nums[0];
        // int fn_1 = nums[0], fn_2 = 0, temp;
        // int fn_1_rob_first = 1, fn_2_rob_first = 0, temp_rob;
        // for (int i=1; i<nums.size()-1; i++) {
        //     if (fn_2 + nums[i] > fn_1) { // 偷
        //         temp = fn_1;
        //         fn_1 = fn_2 + nums[i];
        //         fn_2 = temp;
        //         temp_rob = fn_1_rob_first;
        //         fn_1_rob_first = fn_2_rob_first;
        //         fn_2_rob_first = temp_rob;
        //     } else if (fn_2 + nums[i] < fn_1) {
        //         fn_2 = fn_1;
        //         fn_2_rob_first = fn_1_rob_first;
        //     } else {
        //         fn_2 = fn_1;
        //         temp = fn_1_rob_first;
        //         if (fn_2_rob_first + fn_1_rob_first == 1) temp = 2; // 偷不偷都行
        //         fn_2_rob_first = fn_1_rob_first;
        //         fn_1_rob_first = temp;
        //     }
        // }

        // int res = 0;
        // // 根据倒数第三家有没有偷来判断最后的结果
        // if (fn_2_rob_first == 1) {
        //                     // 偷最后一家                  //偷第一家
        //     res = max(fn_1, max(fn_2-nums[0]+nums.back(), fn_2));
        // } else if (fn_2_rob_first == 0) {
        //     res = max(fn_1, fn_2+nums.back());
        // } else {
        //     res = max(fn_1, max(fn_2-nums[0]+nums.back(), fn_2));
        //     res = max(res, fn_2+nums.back());
        // }
        // return res;

        // solution two
        // ref.:https://leetcode-cn.com/problems/house-robber-ii/solution/tong-yong-si-lu-tuan-mie-da-jia-jie-she-wen-ti-by-/
        // 既然不能同时抢劫第一个房子和最后一个房子
        // 则分为房子里面包含第一个房子或包含最后一个房子两种情况
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        return max(rob_range(nums, 0, n-2), rob_range(nums, 1, n-1));
    }
};
// @lc code=end

