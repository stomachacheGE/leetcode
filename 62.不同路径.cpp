/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths1(int m, int n) {
        // intialization
        if (m == 0 && n == 0) return 0;
        vector<vector<int>> states(m, vector<int>(n, 0));
        for (int i=0; i<m; i++) states[i][0] = 1;
        for (int j=0; j<n; j++) states[0][j] = 1;
        
        // state transfer
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                states[i][j] = states[i-1][j] + states[i][j-1];
            }
        }
        
        return states[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        // solution one
        // dynamic programing
        int res = 0;
        vector<vector<int>> table(m, vector<int>(n));
        for (int i=0; i<n; i++) {
            table[0][i] = 1;
        }
        for (int i=0; i<m; i++) {
            table[i][0] = 1;
        }

        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                table[i][j] = table[i-1][j] + table[i][j-1];
            }
        }
        return table.back().back();

    }
};
// @lc code=end

