/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
private:
    void calculate(stack<int>& nums, stack<char>& opers) {
        char o = opers.top();
        opers.pop();
        int i = nums.top();
        nums.pop();
        int j = nums.top();
        nums.pop();
        int res = 0;
        // cout << "o=" << o << ", i=" << i << ", j=" << j << endl;
        switch (o) {
            case '+': res = i + j; break;
            case '-': res = j - i; break;
            case '*': res = i * j; break;
            case '/': res = j / i; break;
        }
        nums.push(res);
    }
public:
    int calculate(string s) {
        // solution one
        // 先把乘除法算了，再算加减法
        if (s.size() == 0) return 0;
        stack<int> nums;
        stack<char> opers;
        int i = 0, cur = 0, temp = 0;
        bool minus = false;
        while (i < s.size()) {
            // cout << i << endl;
            if (s[i] == ' ') {
                i++;
                continue;
            }

            if (s[i] == '+' || s[i] == '-') {
                opers.push('+');
                if (s[i] == '-') minus = true;
                i++;
                continue;
            }

            if (s[i] == '*' || s[i] == '/') {
                opers.push(s[i]);
                i++;
                while (s[i] == ' ') i++;
                // cout << "i=" << i << endl;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    // cout << "s[i]=" << s[i] << endl;
                    cur *= 10;
                    cur += s[i] - '0';
                    i++;
                }
                // cout << "cur=" << cur << endl;
                if (minus) {
                    cur = -cur;
                    minus = false;
                }
                nums.push(cur);
                calculate(nums, opers);
                cur = 0;
                continue;
            }

            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    cur *= 10;
                    cur += s[i] - '0';
                    i++;
            }
            if (minus) {
                cur = -cur;
                minus = false;
            }
            nums.push(cur);
            cur = 0;
        }

        while (!opers.empty()) {
            calculate(nums, opers);
        }

        return nums.top();

        // solution two
        // 代码可以更简单，用一个栈就行(TODO)
        // ref.:https://leetcode-cn.com/problems/basic-calculator-ii/submissions/
    }
};
// @lc code=end

