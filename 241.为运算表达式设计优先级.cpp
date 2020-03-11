/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        // solution one
        // divide and conqure
        // ref.https://leetcode-cn.com/problems/different-ways-to-add-parentheses/solution/yi-yun-suan-fu-wei-jie-liang-bian-fen-zhi-by-gloom/
        vector<int> res;
        if (input.empty()) return res;

        bool is_number = true;
        for (auto c: input) {
            if (c == '*' || c == '-' || c == '+') {
                is_number = false;
                break;
            }
        }
        if (is_number) {
            res.push_back(stoi(input));
            return res;
        }

        for (int i=1; i<input.size()-1; i++) {
            if (input[i] == '*' || input[i] == '-' || input[i] == '+') { // 以运算符为界限
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for (auto l: left) {
                    for (auto r: right) {
                        if (input[i] == '*') {
                            res.push_back(l * r);
                        } else if (input[i] == '-') {
                            res.push_back(l - r);
                        } else if (input[i] == '+') {
                            res.push_back(l + r);
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

