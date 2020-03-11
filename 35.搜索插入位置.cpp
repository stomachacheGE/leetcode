/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert1(vector<int>& nums, int target) {
        // solution one (v2)
        if (nums.size() == 0) return 0;
        int i = 0, j = nums.size() - 1, mid;
        while (i < j) {
            mid = i + (j - i) / 2;
            if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
    
        return nums[i] < target ? i+1 : i; // 检查退出条件
    }

    int searchInsert(vector<int>& nums, int target) {
        // solution one (v2)
        if (nums.size() == 0) return 0;
        int i = 0, j = nums.size(), mid; // 注意右边界是nums.size()
        while (i < j) {
            mid = i + (j - i) / 2;
            if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
    
        return i;
    }
};
// @lc code=end

