/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search1(vector<int>& nums, int target) {
        // Solution one
        // 先确定target和nums[mid]的大小关系
        // 再判断在分界点左边还是右边
        // int size = nums.size();
        // if (size == 0) return -1;
        // int left = 0, right = size - 1, mid;
        // while (left <= right) {
        //     mid = left + (right - left) / 2;
        //     if (nums[mid] == target) {
        //         return mid;
        //     } else if (nums[mid] < target) {
        //         if (nums[mid] >= nums[left]) { // 在分界点左边
        //             left = mid + 1;
        //         } else {                       // 在分界点右边
        //             if (target <= nums[right]) {
        //                 left = mid + 1;
        //             } else {
        //                 right = mid - 1;
        //             }
        //         }
        //     } else {
        //         if (nums[mid] >= nums[left]) { // 在分界点左边
        //             if (target >= nums[left]) {
        //                 right = mid - 1;
        //             } else {
        //                 left = mid + 1;
        //             } 
        //         } else {                      // 在分界点右边
        //             right = mid - 1;
        //         }
        //     }
        // }
        // return -1;

        // Solution two
        // 先判断在分界点的左边右边
        // 再确定target和nums[mid]的大小关系
        // 这种方法比solution one代码更简洁
        // int size = nums.size();
        // if (size == 0) return -1;
        // int left = 0, right = size - 1, mid;
        // while (left <= right) {
        //     mid = left + (right - left) / 2;
        //     if (nums[mid] == target) {
        //         return mid;
        //     }

        //     if (nums[mid] >= nums[left]) { // 在分界点左边
        //         if (target < nums[mid] && nums[left] <= target) {
        //             right = mid - 1;
        //         } else {
        //             left = mid + 1;
        //         }
        //     } else {                       // 在分界点右边
        //         if (target > nums[mid] && nums[right] >= target) {
        //             left = mid + 1;
        //         } else {
        //             right = mid - 1;
        //         }
        //     }
        // }
        // return -1;


        // solution one (v2)
        if (nums.size() == 0) return -1;
        int i = 0, j = nums.size() - 1, mid;
        while (i < j) {
            mid = i + (j - i + 1) / 2;
            // on the left
            if (nums[mid] >= nums[i]) {
                if (nums[i] <= target && nums[mid] > target) {
                    j = mid - 1;
                } else {
                    i = mid;
                }
            } else {
                if (nums[j] >= target && nums[mid] <= target) {
                    i = mid;
                } else {
                    j = mid - 1;
                }
            }
        }
        return nums[i] == target ? i : -1;

    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int i = 0, j = nums.size() - 1, mid;
        while (i < j) {
            mid = i + (j - i) / 2;
            // on the left
            if (nums[mid] >= nums[i]) {
                if (target >= nums[i] && target <= nums[mid]) {
                    j = mid;
                } else {
                    i = mid + 1;
                }
            } else {
                if (nums[j] >= target && nums[mid] < target) {
                    i = mid + 1;
                } else {
                    j = mid;
                }
            }
        }
        return nums[i] == target ? i : -1;
    }
};
// @lc code=end

