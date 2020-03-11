/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // solution one
        // ref.:https://leetcode-cn.com/problems/fraction-to-recurring-decimal/solution/fen-shu-dao-xiao-shu-by-leetcode/
        // 自己想题解的时候，循环最多到denominator层，
        // 因为小数点后的位数最多为denominator个，这个结论对吗？
        // 实际算法中，用remainder != 0 + break 来实现
        if (numerator == 0) return "0";
        string res = "";
        bool minus = (numerator<0) ^ (denominator<0);
        long dividend = (long) numerator, divisor = (long) denominator;
        if (dividend < 0) dividend = -dividend;
        if (divisor < 0) divisor = -divisor;

        res += to_string(dividend / divisor);
        long remainder = dividend % divisor;
        if (remainder != 0) res += ".";
        unordered_map<int, int> remainder2idx;
        while (remainder != 0) {
            auto it = remainder2idx.find(remainder);
            if (it != remainder2idx.end()) {
                res.insert(remainder2idx[remainder], 1, '(');
                res += ")";
                break;
            }

            remainder2idx[remainder] = res.size();
            remainder *= 10;
            if (remainder < divisor) {
                res += "0";
                continue;
            } else {
                res += to_string(remainder / divisor);
                remainder %= divisor;
            }
        }
        if (minus) res.insert(0, 1, '-');
        return res;
    }
};
// @lc code=end

