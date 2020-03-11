/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Solution one
        // Dutch national flag problem
        // Ref.:https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-by-leetcode/
        // 三个指针，一个指向0的最右边界，一个指向2的最左边界，一个指向当前
        // int size = nums.size();
        // if (size <= 1) return;
        // int i = 0, j = size - 1, cur = 0, temp;
        // while (cur <= j) {
        //     if (nums[cur] == 0) {
        //         temp = nums[i];
        //         nums[i] = nums[cur];
        //         nums[cur] = temp;
        //         i++;
        //         cur++;
        //     } else if (nums[cur] == 2) {
        //         temp = nums[j];
        //         nums[j] = nums[cur];
        //         nums[cur] = temp;
        //         j--;
        //     } else {
        //         cur++;
        //     }
        // }

        // solution one (v2)
        if (nums.size() < 2) return;
        int m = 0, i = 0, j = nums.size()-1;
        while (m <= j) { // must include =
            if (nums[m] == 0) {
                nums[m] = nums[i];
                nums[i] = 0;
                i++;
                m++;
            } else if (nums[m] == 2) {
                nums[m] = nums[j];
                nums[j] = 2;
                j--;
            } else {
                m++;
            }
        }
    }
};
// @lc code=end

