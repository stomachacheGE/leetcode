/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses1(string s) {
        // solution one
        // stack
        // cannot pass 155/230: "()(()"
        // stack<char> st;
        // bool consecutive = true;
        // int  cur = 0, res = 0;
        // for (auto &c: s) {
        //     if (c == '(') {
        //         st.push(c);
        //         continue;
        //     }

        //     if (c == ')' && (st.empty() || st.top() != '(')) {
        //         consecutive = false;
        //         cur = 0;
        //         // cout << "case1: cur = " << cur << endl;
        //     } else {
        //         st.pop();
        //         // cout << "case2: cur = " << cur << endl;
        //         cur = cur + 2;
        //         // cout << "case2: cur = " << cur << endl;
        //         res = max(cur, res);
        //     }
        // }
        // return res;

        // solution two
        // dynamice programming
        // 利用pandrolime的思想，从里到外
        // cannot pass 118/230: ")(((((()())()()))()(()))("
        // int len = s.size();
        // int res = 0;
        // for (int i=0; i<len-1; i++) {
        //     // cout << "i=" << i << endl;
        //     if (!(s[i] == '(' && s[i+1] == ')')) continue;
        //     int p = i-1, q = i+2;
        //     // cout << "out1: p=" << p << ", q=" << q << endl;
        //     while (true) {
        //         // cout << "out2: p=" << p << ", q=" << q << endl;
        //         if (p >=0 && s[p] == '(' && q < len && s[q] == ')') {
        //             p--;
        //             q++;
        //         } else if (p >=1 && s[p] == ')' && s[p-1] == '(') {
        //             p--;
        //             p--;
        //         } else if (q < len-1 && s[q] == '(' && s[q+1] == ')') {
        //             q++;
        //             q++;
        //         } else {
        //             break;
        //         }
        //     }
        //     if (q-p-1 > res) {
        //         cout << "p=" << p << ", q=" << q << endl;
        //     }
        //     res = max(res, q-p-1);
        // }
        // return res;

        // solution three
        // ref.:https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/
        // dynamic program
        // 每个位置的状态是以它为尾最长有效子串的个数
        int len = s.size(), res = 0;
        if (len == 0) return 0;
        vector<int> state(len, 0);
        for (int i = 1; i<len; i++) {
            // cout << i << endl;
            if (s[i] == ')' && s[i-1] == '(') {
                state[i] = i >= 2 ? state[i-2] + 2 : 2;
            } else if (s[i] == ')' && s[i-1] == ')') {
                if (i-1-state[i-1] >= 0 && s[i-1-state[i-1]] == '(') {
                    int before = i-state[i-1]-2 >= 0 ? state[i-state[i-1]-2] : 0;
                    state[i] = state[i-1] + before + 2;
                }
            }
            res = max(res, state[i]);
        }
        return res;

        // solution four
        // stack (TODO)
    }

    int longestValidParentheses(string s) {

        // solution one
        // not work for case ")()())"
        // if (s.empty()) return 0;
        // int n = s.size(), res = 0;
        // vector<vector<bool>> states(n, vector<bool>(n, false));
        // for (int i=n-2; i>=0; i--) {
        //     for (int j=i+1; j<n; j++) {
        //         if (s[i] == '(' && s[j] == ')') {
        //             states[i][j] = true;
        //             if (i+1 <= j-1) {
        //                 states[i][j] = states[i][j] && states[i+1][j-1];
        //             }
        //             if (states[i][j]) {
        //                 res = max(res, j-i+1);
        //             }
        //         }
        //     }
        // }
        // return res;

        // solution two
        
        if (s.empty()) return 0;
        s.insert(0, 1, ' ');
        int len = s.size(), res = 0;
        vector<int> states(len, 0);
        for (int i=2; i<len; i++) {
            if (s[i] == ')' && s[i-1] == '(') {
                states[i] = states[i-2] + 2;
            } else if (s[i] == ')' && s[i-1] == ')') {
                if (s[i-1-states[i-1]] == '(') {
                    states[i] = states[i-1] + states[i-1-states[i-1]-1] + 2;
                }
            }
            res = max(res, states[i]);
        }
        return res;
    }
};
// @lc code=end

