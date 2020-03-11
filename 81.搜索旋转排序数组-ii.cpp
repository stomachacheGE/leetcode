/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {

        // solution one
        // 此题和33题的最大区别在于，当nums[left] == nums[mid]的时候
        // 不能区分在分界点左边还是右边
        // 最暴力的方式在相等的时候，退化为顺序搜索
        // int size = nums.size();
        // if (size == 0) return false;
        // int left = 0, right = size - 1, mid;
        // while (left <= right) {
        //     mid = left + (right - left) / 2;
        //     if (nums[mid] == target) {
        //         return true;
        //     }

        //     if (nums[mid] > nums[left]) {          // 在分界点左边
        //         if (target < nums[mid] && nums[left] <= target) {
        //             right = mid - 1;
        //         } else {
        //             left = mid + 1;
        //         }
        //     } else if (nums[mid] < nums[left]) {    // 在分界点右边
        //         if (target > nums[mid] && nums[right] >= target) {
        //             left = mid + 1;
        //         } else {
        //             right = mid - 1;
        //         }
        //     } else {                      // 不能区分，退化为顺序搜索
        //         for (int i=left; i<=right; i++) {
        //             if (nums[i] == target) {
        //                 return true;
        //             }
        //         }
        //         return false;
        //     }
        // }
        // return false;

        // Solution two
        // Ref.:https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/zai-javazhong-ji-bai-liao-100de-yong-hu-by-reedfan/
        // 以上解法中退化为顺序搜索不是太elegant
        // 当nums[left] == nums[mid]的时候
        // 只需要将left++就可，排除了此干扰项
        // int size = nums.size();
        // if (size == 0) return false;
        // int left = 0, right = size - 1, mid;
        // while (left <= right) {
        //     mid = left + (right - left) / 2;
        //     if (nums[mid] == target) {
        //         return true;
        //     }

        //     if (nums[mid] > nums[left]) {          // 在分界点左边
        //         if (target < nums[mid] && nums[left] <= target) {
        //             right = mid - 1;
        //         } else {
        //             left = mid + 1;
        //         }
        //     } else if (nums[mid] < nums[left]) {    // 在分界点右边
        //         if (target > nums[mid] && nums[right] >= target) {
        //             left = mid + 1;
        //         } else {
        //             right = mid - 1;
        //         }
        //     } else {                      // 不能区分，排除干扰项
        //         left++;
        //     }
        //     // cout << "left = " << left << ", right = " << right << endl;
        // }
        // return false;

        // solution one (v2)
        if (nums.size() == 0) return false;
        int i = 0, j = nums.size()-1, mid;
        while (i < j) {
            mid = i + (j - i) / 2;
            if (nums[i] < nums[mid]) {
                if (target >= nums[i] && nums[mid] >= target) {
                    j = mid;
                } else {
                    i = mid + 1;
                }
            } else if (nums[i] > nums[mid]) {
                if (target < nums[i] && nums[mid] < target) {
                    i = mid + 1;
                } else {
                    j = mid;
                }
            } else {
                if (nums[i] == target) return true;
                i++; // in this case, cannot tell target is on which side
            }
        }
        return nums[i] == target ? true : false;

    }
};
// @lc code=end

