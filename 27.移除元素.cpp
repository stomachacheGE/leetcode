/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // solution one
        // 前后两个指针向中间靠拢
        // if (nums.size() == 0) return 0;
        // int left = 0, right = nums.size() - 1, temp;
        // while (left <= right) {
        //     while (left < nums.size() && nums[left] != val) left++;
        //     while (right >= 0 && nums[right] == val) right--;
        //     if (left > right) break;
        //     // 不用交换，直接覆盖就可以, 但是要递减right
        //     // temp = nums[right];
        //     // nums[right] = nums[left];
        //     // nums[left] = temp;
        //     nums[left] = nums[right];
        //     right--;
        // }
        // return right + 1;

        // solution two
        // 从左到右，右指针始终指向不等于val的位置，并覆盖左指针
        // 可能需要多次移动
        // ref.:https://leetcode-cn.com/problems/remove-element/solution/yi-chu-yuan-su-by-leetcode/
        if (nums.size() == 0) return 0;
        int left = 0;
        for (int right=0; right<nums.size(); right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};
// @lc code=end

