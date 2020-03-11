/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {

        // solution one
        // ref.:https://leetcode-cn.com/problems/number-of-digit-one/solution/shu-zi-1-de-ge-shu-by-leetcode/
        int res = 0;
        long cur = 1;
        while (cur <= n) {  // must include equal
            res += (n / (cur * 10)) * cur;
            res += min(max(n % (cur * 10) - cur + 1, long(0)), cur);
                        // 当前所在位为1                     当前所在位大于1
            cur *= 10;
        }
        return res;
    }
};
// @lc code=end

