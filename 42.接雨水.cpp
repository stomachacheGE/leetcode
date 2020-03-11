/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // solution one
        // ref.:https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/
        // brute-force
        // 分别找当前点左边和右边的最大值
        // 当前值的出水量就应该为左右最大值的最小值
        // 复杂度为O(n**2)
        // if (height.size() <= 2) return 0;
        // int left_max = 0, right_max = 0, res = 0, temp;
        // for (int i=1; i < height.size()-1; i++) {
        //     left_max = 0;
        //     right_max = 0;
        //     for (int j=i; j>=0; j--) left_max = max(left_max, height[j]);
        //     for (int j=i; j<height.size(); j++) right_max = max(right_max, height[j]);
        //     temp = min(left_max, right_max);
        //     res += temp - height[i];
        // }
        // return res;

        // solution two
        // 可以事先先把左右值求出来，再最后比较
        // 时间复杂度为O(n), 空间复杂度为O(n)
        // if (height.size() <= 2) return 0;
        // vector<int> left_maxs(height.size(), 0);
        // int left_max = 0, right_max = 0, res = 0;
        // for (int i=0; i<height.size(); i++) {
        //     left_max = max(left_max, height[i]);
        //     left_maxs[i] = left_max;
        // }
        // for (int i=height.size()-1; i>=0; i--) {
        //     right_max = max(right_max, height[i]);
        //     res += min(right_max, left_maxs[i]) - height[i];
        // }
        // return res;

        // solution three
        // two-pointer (TODO)
        // 非常棒的算法
        // 时间复杂度O(n), 空间复杂度O(1)
        if (height.size() <= 2) return 0;
        int left_max = 0, right_max = 0, i = 0, j = height.size()-1, res = 0;
        while (i <= j) {
            if (height[i] < height[j]) {
            // 下面的条件判断也适用
            // if (left_max < right_max) {
                left_max = max(left_max, height[i]);
                res += left_max - height[i];
                i++;
            } else {
                right_max = max(right_max, height[j]);
                res += right_max - height[j];
                j--;
            }
        }        
        return res;
        // solution four
        // stack (TODO)
    }
};
// @lc code=end

