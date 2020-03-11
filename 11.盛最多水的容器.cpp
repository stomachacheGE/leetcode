/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {

        // Solution one
        // Ref.:https://leetcode-cn.com/problems/container-with-most-water/solution/sheng-zui-duo-shui-de-rong-qi-by-leetcode/
        // two pointers
        // 一前一后两个指针，并向中间移动值较小的那个指针
        // 证明此方法不会错过最佳解法（TODO）

        // int i = 0, j = height.size() - 1;
        // int res = 0, cur_area = 0;
        // while (i < j) {
        //     cur_area = (j - i) * min(height[i], height[j]);
        //     if (cur_area > res) res = cur_area;
        //     if (height[i] < height[j]) i++;
        //     else j--;
        // }
        // return res;

        // solution one (v2)
        // 两个指针，向中间移动值较小的那个
        // 因为只有移动较小的那个，才可能在移动后面积更大
        int res = INT_MIN, i = 0, j = height.size()-1;
        while (i < j) {
            int area = min(height[i], height[j]) * (j-i);
            // cout << area << endl;
            if (area > res) res = area;
            if (height[i] < height[j] && i < height.size()-1) i++;
            else if (height[i] >= height[j] && j > 0) j--;
        }
        return res;
    }
};
// @lc code=end

