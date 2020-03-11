/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res{-1, -1};
        if (nums.empty()) return res;
        int l = 0, r = nums.size()-1, mid;
        int idx1 = -1, idx2 = -1;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (nums[l] == target) res[0] = l;
        else return res;
        l = 0, r = nums.size()-1;
        while (l < r) {
            mid = l + (r - l + 1) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid;
            } 
        }
        res[1] = l;
        return res;
    }
};
// @lc code=end

