/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct1(string s, string t) {
        // initialization
        int m = s.size(), n = t.size();
        vector<vector<long>> states(m+1, vector<long>(n+1, 0));
        states[0][0] = 1;
        for (int i=1; i<=m; i++) {
            states[i][0] = 1;
        }

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (s[i-1] == t[j-1]) {
                    states[i][j] = states[i-1][j-1] + states[i-1][j];
                    //                 select           not select
                } else {
                    states[i][j] = states[i-1][j];
                }
            // cout << "state["<<i<<"]["<<j<<"]=" << states[i][j] << endl;
            }
        }
        return states[m][n];
    }

    int numDistinct(string s, string t) {

        // dynamic programming
        if (s.size() < t.size()) return 0;
        if (s.size() == 0) return 0;
        int m = s.size(), n = t.size();
        vector<vector<long>> states(m+1, vector<long>(n+1, 0));
        states[m][n] = 1;
        for (int i=0; i<=m; i++) {
            states[i][n] = 1;
        }
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (s[i] == t[j]) {
                    states[i][j] = states[i+1][j+1] + states[i+1][j];
                } else {
                    states[i][j] = states[i+1][j];
                }
            }
        }
        return int(states[0][0]);

    }
};
// @lc code=end

