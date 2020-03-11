/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // solution one
        if (nums.size() == 1) return 0;
        int l = 0, r = nums.size() - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < nums[mid+1]) { // since num[-1] = nums[n] = -inf,
                                           // there must be a peak if the element increases
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

