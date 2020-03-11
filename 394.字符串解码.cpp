/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {

        // solution one
        string res;
        string cur, cur_rept;
        stack<char> st;
        for (auto &c: s) {
            if (c != ']') {
                st.push(c);
                continue;
            }
            cur = "";
            cur_rept = "";
            while (!st.empty() && st.top() != '[') {
                cur.insert(0, 1, st.top());
                st.pop();
            }
            st.pop(); // pop '['
            int times = 0, level = 1;
            while (!st.empty() && st.top()-'0' >= 0 && st.top()-'0' <=9) {
                times += (st.top() - '0') * level;
                level *= 10;
                st.pop();
            }
            while (times-- >= 1) {
                cur_rept += cur;
            }
            if (st.empty()) {
                res += cur_rept;
            } else {
                for (auto &cc: cur_rept) {
                    st.push(cc);
                }
            }
        }
        int num = res.size();
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            res.insert(num, 1, c);
        }
        return res;
    }
};
// @lc code=end

