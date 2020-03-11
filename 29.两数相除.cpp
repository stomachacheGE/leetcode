/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
#define LIMIT 0x80000000
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Solution One
        // Ref.:https://leetcode-cn.com/problems/divide-two-integers/comments/46284
        if (dividend == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        bool negative = (dividend ^ divisor) < 0;
        unsigned int divd = dividend == INT_MIN ? LIMIT : abs(dividend);
        unsigned int divs = divisor == INT_MIN ? LIMIT : abs(divisor);
        unsigned int res = 0;

        for (int i=31; i>=0; i--) {
            if ((divd >> i) >= divs) {
                res += ((unsigned int) 1 << i); // 商
                divd -= (divs << i); // 余数
            }
        }
        // cout << "res = " << res << endl;
        return negative ? -(int)res : (int)res;
    }
};
// @lc code=end

