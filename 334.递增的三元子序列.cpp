/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // solution one
        // 时间空间复杂度都为O(n)
        // if (nums.size() < 3) return false;
        // vector<bool> flag1(nums.size(), false), flag2(nums.size(), false);
        // int cur_min = nums[0], cur_max = nums.back();
        // for (int i=0; i<nums.size(); i++) {
        //     if (nums[i] > cur_min) flag1[i] = true;
        //     cur_min = min(cur_min, nums[i]);
        // }
        // for (int i=nums.size()-2; i>=0; i--) {
        //     if (nums[i] < cur_max) flag2[i] = true;
        //     cur_max = max(cur_max, nums[i]);
        // }
        // for (int i=1; i<nums.size()-1; i++) {
        //     if (flag1[i] && flag2[i]) return true;
        // }
        // return false;

        // solution two
        // ref.:https://leetcode-cn.com/problems/increasing-triplet-subsequence/solution/c-xian-xing-shi-jian-fu-za-du-xiang-xi-jie-xi-da-b/
        // 双指针
        if (nums.size() < 3) return false;
        int small = INT_MAX, mid = INT_MAX;
        for (auto &num: nums) {
            if (num <= small) small = num; // = is necessary
            else if (num <= mid) mid = num; // = is necessary
            else if (num > mid) return true;
        }
        return false;

    }
};
// @lc code=end

