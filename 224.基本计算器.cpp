/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
private:
    void calculate(stack<int>& nums, stack<char>& oper) {
        char o = oper.top();
        oper.pop();
        int m = nums.top();
        nums.pop();
        int n = nums.top();
        nums.pop();
        // cout << "o=" << o << ", m=" << m << ", n=" << n << endl;
        int res = 0;
        if (o == '-') res = n - m;
        if (o == '+') res = n + m;
        nums.push(res);
    }
public:
    int calculate(string s) {
        int brackets = 0, cur_num = 0, i = 0;
        stack<int> nums;
        stack<char> oper;
        while (i < s.size()) {
            // cout << i << endl;
            if (s[i] == ' ') {
                i++; 
                continue;
            }

            if (s[i] == '+' || s[i] == '-') {
                oper.push(s[i]);
                i++;
                continue;
            }

            if (s[i] == '(') {
                oper.push(s[i]);
                brackets++;
                i++;
                continue;
            }

            if (s[i] == ')') {
                oper.pop();
                if (!oper.empty() && (oper.top() == '+' || oper.top() == '-')) calculate(nums, oper);
                brackets--;
                i++;
                continue;
            }

            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                cur_num *= 10;
                cur_num += (s[i] - '0');
                i++;
            }
            nums.push(cur_num);
            cur_num = 0;

            if (!oper.empty() && (oper.top() == '+' || oper.top() == '-')) calculate(nums, oper);
        }
        return nums.top();
    }
};
// @lc code=end

