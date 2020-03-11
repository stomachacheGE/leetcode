/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.28%)
 * Total Accepted:    689.9K
 * Total Submissions: 2.7M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */
#include <cmath>
class Solution {
public:
    int reverse(int x) {
        ////////// Solution One (From Solution)//////////
        // Ref. 1:https://leetcode.com/problems/reverse-integer/discuss/4243
        // Ref. 2:https://stackoverflow.com/questions/7594508/modulo-operator-with-negative-values
        // Note, the % operator in C++ may give negative number as output, which is not
        // really the modulo operation in math.
        // long result = 0;
        // while(x != 0)
        // {
        //     result = result*10 + x % 10;
        //     x /= 10;
        // }
        // return (result > INT_MAX || result < INT_MIN)? 0 : result;

        ////////// Solution Two (From Solution)//////////
        // Not using long, check overflow manually
        // Ref.:https://leetcode.com/problems/reverse-integer/solution/
        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            if (res > INT_MAX/10 || (res == INT_MAX/10 && digit > 7)) return 0;
            if (res < INT_MIN/10 || (res == INT_MIN/10 && digit < -8)) return 0;
            res = res * 10 + digit;
            x /= 10;
        }
        return res;
    }
};
