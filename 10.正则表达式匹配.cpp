/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch1(string s, string p) {
        // solution one
        // brute-force recursion
        // ref.:https://leetcode-cn.com/problems/regular-expression-matching/solution/ji-yu-guan-fang-ti-jie-gen-xiang-xi-de-jiang-jie-b/151942
        // if (!p[0]) return (!s[0]);
        // bool first_match = s[0] && (s[0] == p[0] || p[0] == '.');
        // if (p[1] == '*') {
        //     return isMatch(s, &p[2]) || (first_match && isMatch(&s[1], p));
        // } else {
        //     return first_match && isMatch(&s[1], &p[1]);
        // }

        // solution two
        // dynamic programming
        // ref.:https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode/
        int len_s = s.size(), len_p = p.size();
        bool table[len_s+1][len_p+1];
        table[len_s][len_p] = true;
        for (int i=0; i<len_s; i++) {
            table[i][len_p] = false;
        }
        // 最后一行不需要初始化，考虑case s="aa" p="a*"
        // for (int i=0; i<len_p; i++) {
        //     table[len_s][i] = false;
        // }
        for (int i=len_s; i>=0; i--) {
            for (int j=len_p-1; j>=0; j--) {
                bool first_match = (i < len_s) && (s[i] == p[j] || p[j] == '.');
                if (j+1 < len_p && p[j+1] == '*') {
                    table[i][j] = table[i][j+2] || (first_match && table[i+1][j]);
                } else {
                    table[i][j] = first_match && table[i+1][j+1];
                }
            }
        }
        return table[0][0];
    }

    bool isMatch(string s, string p) {
        // recursion
        if (p.empty()) return s.empty();
        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p[1] == '*') {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        } else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    } 
};
// @lc code=end
