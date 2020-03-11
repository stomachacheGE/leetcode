/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {

        // Solution One
        // unordered_map<int, char> intToChar({
        //     {1,    'I'},
        //     {5,    'V'},
        //     {10,   'X'},
        //     {50,   'L'},
        //     {100,  'C'},
        //     {500,  'D'},
        //     {1000, 'M'}
        // });

        // int order = 1, residual;
        // string res;
        // while (num) {
        //     residual = num % 10;
        //     if (residual == 0) {
                
        //     } else if (residual <= 3) {
        //         res.insert(0, residual, intToChar[order]);
        //     } else if (residual == 4) {
        //         res.insert(0, 1, intToChar[order*5]);
        //         res.insert(0, 1, intToChar[order]);
        //     } else if (residual == 5) {
        //         res.insert(0, 1, intToChar[order*5]);
        //     } else if (residual == 9) {
        //         res.insert(0, 1, intToChar[order*10]);
        //         res.insert(0, 1, intToChar[order]);
        //     } else {
        //         res.insert(0, residual-5, intToChar[order]);
        //         res.insert(0, 1, intToChar[order*5]);
        //     }
        //     num /= 10;
        //     order *= 10;
        // }
        // return res;

        // Solution two
        // Ref.:https://leetcode-cn.com/problems/integer-to-roman/solution/zheng-shu-zhuan-luo-ma-shu-zi-cshi-xian-liang-chon/
        // 贪心法：尽可能用最少的罗马数字表示该数字
        // 注意此处必须使用map，而不是unordered_map
        map<int, string> table({
            {1000,  "M"},
            {900,   "CM"},
            {500,   "D"},
            {400,   "CD"},
            {100,   "C"},
            {90,    "XC"},
            {50,    "L"},
            {40,    "XL"},
            {10,    "X"},
            {9,     "IX"},
            {5,     "V"},
            {4,     "IV"},
            {1,     "I"}
        });

        string res;
        // 因为数字需要从1000开始，1结束，因此使用rbegin()，而不是begin()
        for (auto it=table.rbegin(); it!=table.rend(); it++) {
            // cout << it->first << ": " << it->second << endl;
            while (num >= it->first) {
                res += it->second;
                num -= it->first;
            }
        }
        return res;
    }
};
// @lc code=end

