/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
private:
    string parenthesis = "()";

    void backtracking(string curString, int idx, int num, int numLeft, int numRight, vector<string> &res) {

        if (idx == num * 2) {
            if (numLeft == num && numRight == num) {
                res.push_back(curString);
            }          
            return;
        }

        // (的数量必然大于等于)的数量
        if (numRight > numLeft) return;

        for (auto &c: parenthesis) {
            curString.push_back(c);
            if (c == '(') {
                backtracking(curString, idx+1, num, numLeft+1, numRight, res);
            } else if (c == ')') {
                backtracking(curString, idx+1, num, numLeft, numRight+1, res);
            }
            curString.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        // Solution One
        // 类似于求所有组合的思路
        // 但是在回溯的过程中需要判断合法性
        // 即(的数量必然大于等于)的数量

        vector<string> res;
        if (n == 0) return res;

        string curString;
        backtracking(curString, 0, n, 0, 0, res);
        return res;
    }
};
// @lc code=end

