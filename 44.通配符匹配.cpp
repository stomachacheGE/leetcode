/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch1(string s, string p) {
        // dynamic programming
        int len_s = s.size(), len_p = p.size();
        vector<vector<bool>> state(len_s+1, vector<bool>(len_p+1, false));
        state[len_s][len_p] = true;
        for (int i=len_s; i>=0; i--) {
            for (int j=len_p-1; j>=0; j--) {
                if (p[j] == '*') {
                    state[i][j] = (i+1 <=len_s && (state[i+1][j+1] || state[i+1][j])) || state[i][j+1];
                } else if (p[j] == '?') {
                    state[i][j] = i+1 <=len_s ? state[i+1][j+1] : false;
                } else if (i+1 <= len_s && p[j] == s[i]) {
                    state[i][j] = i+1 <= len_s ? state[i+1][j+1] : false;
                }
                // cout << "i=" << i << ", j=" << j << ", " << state[i][j] << endl;
            }
        }
        return state[0][0];

    }

    bool isMatch(string s, string p) {
        // dynamic programming
        int len_s = s.size(), len_p = p.size();
        vector<vector<bool>> state(len_s+1, vector<bool>(len_p+1, false));
        state[len_s][len_p] = true;
        for (int i=len_p-1; i>=0; i--) {
            if (p[i] == '*') {
                state[len_s][i] = state[len_s][i+1];
            }
        }
        for (int i=len_s-1; i>=0; i--) {
            for (int j=len_p-1; j>=0; j--) {
                if (p[j] == '*') {
                    state[i][j] = state[i+1][j+1] || state[i+1][j] || state[i][j+1];
                } else if (p[j] == '?' || p[j] == s[i]) {
                    state[i][j] = state[i+1][j+1];
                } 
                // cout << "i=" << i << ", j=" << j << ", " << state[i][j] << endl;
            }
        }
        return state[0][0];

        // solution two
        // recursion
        // time limit exceeded, passed 939/1809
        // if (p.empty()) return s.empty();
        // if (p[0] == '?' || (s[0] == p[0])) return s.empty() ? false : isMatch(s.substr(1), p.substr(1));
        // if (p[0] == '*') {
        //     if (s.empty()) return isMatch(s, p.substr(1));
        //     else return isMatch(s, p.substr(1)) || isMatch(s.substr(1), p.substr(1)) || isMatch(s.substr(1), p);
        // }
        // return false;

    }
};
// @lc code=end

