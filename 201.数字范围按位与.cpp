/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {

        // solution one
        // ref.:https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--41/
        int zeros = 0;
        while (n > m) {
            zeros++;
            n = n >> 1;
            m = m >> 1;
        }
        return m << zeros;
        
    }
};
// @lc code=end

