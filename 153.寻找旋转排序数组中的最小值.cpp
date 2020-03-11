/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // solution one
        // if (nums.size() == 1) return nums[0];
        // int i = 0, j = nums.size()-1, mid;
        // while (i < j) {
        //     mid = i + (j - i) / 2;

        //     if (nums[i] <= nums[j]) return nums[i];

        //     if (nums[mid] >= nums[i]) {
        //         i = mid + 1;
        //     } else {
        //         j = mid;
        //     }
        // }
        // return nums[i];

        // solution two
        // more elegant
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size()-1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return nums[left];


    }
};
// @lc code=end

