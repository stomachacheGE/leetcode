/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    vector<string> keyborad {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtracing(string curString, int idx, int numDigits, string digits, vector<string> &res) {

        if (curString.size() == numDigits) {
            res.push_back(curString);
            return;
        }

        string letters = keyborad[digits[idx]-'2'];
        for (int i=0; i<letters.size(); i++) {
            curString.push_back(letters[i]);
            backtracing(curString, idx+1, numDigits, digits, res);
            curString.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {

        // Solution One
        // 回溯法求组合
        int numDigits = digits.size();
        vector<string> res;
        if (numDigits == 0) return res;

        string curString;
        backtracing(curString, 0, numDigits, digits, res);
        return res;
    }
};
// @lc code=end

