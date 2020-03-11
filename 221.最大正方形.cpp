/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare1(vector<vector<char>>& matrix) {
        
        // solution one
        // dynamice programming
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();

        vector<vector<int>> table(m, vector<int>(n, 0));
        int res = 0;
        for (int i=0; i<n; i++) {
            if (matrix[0][i] == '1') {
                table[0][i] = 1;
                res = 1;
            }
        }
        for (int j=1; j<m; j++) {
            if (matrix[j][0] == '1') {
                table[j][0] = 1;
                res = 1;
            }
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                bool valid = true;
                int len = sqrt(table[i-1][j-1]), c = 0;
                while (c <= len) {
                    if (matrix[i][j-c] == '0' || matrix[i-c][j] == '0') {
                        valid = false;
                        break;
                    }
                    c++;
                }

                if (!valid) {
                    if (matrix[i][j] == '0') table[i][j] = 0;
                    else table[i][j] = pow(c, 2);
                    // cout << "i=" << i << ", j=" << j << ", " << table[i][j] << endl;
                    continue;
                }

                table[i][j] = pow(sqrt(table[i-1][j-1])+1, 2);
                // cout << "i=" << i << ", j=" << j << ", " << table[i][j] << endl;
                res = max(table[i][j], res);
            }
        }
        return res;

        // solution two
        // ref.:https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode/
        // 状态转移不用那么复杂
        // int m = matrix.size();
        // if (m == 0) return 0;
        // int n = matrix[0].size();

        // vector<vector<int>> table(m, vector<int>(n, 0));
        // int res = 0;
        // for (int i=0; i<n; i++) {
        //     if (matrix[0][i] == '1') {
        //         table[0][i] = 1;
        //         res = 1;
        //     }
        // }
        // for (int j=1; j<m; j++) {
        //     if (matrix[j][0] == '1') {
        //         table[j][0] = 1;
        //         res = 1;
        //     }
        // }
        // for (int i=1; i<m; i++) {
        //     for (int j=1; j<n; j++) {
        //         if (matrix[i][j] == '1') {
        //             table[i][j] = min(min(table[i-1][j], table[i][j-1]), table[i-1][j-1])+1;
        //             res = max(table[i][j], res);
        //         } else {
        //             table[i][j] = 0;
        //         }
                
        //     }
        // }
        // return res * res;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // solution one
        // dynamic programming
        // 思路不对，有可能和下边或者右边的构成最大
        // 67/69个case错误
        // if (matrix.empty() || matrix[0].empty()) return 0;
        // int n = matrix.size(), m = matrix[0].size(), max_len = 0;
        // vector<vector<int>> states(n, vector<int>(m, 0));
        // for (int i=n-1; i>=0; i--) {
        //     states[i][m-1] = matrix[i][m-1] == '1' ? 1 : 0;
        //     max_len = max(max_len, states[i][m-1]);
        // }
        // for (int i=m-1; i>=0; i--) {
        //     states[n-1][i] = matrix[n-1][i] == '1' ? 1 : 0;
        //     max_len = max(max_len, states[n-1][i]);
        // }

        // for (int i=n-2; i>=0; i--) {
        //     for (int j=m-2; j>=0; j--) {
        //         if (matrix[i][j] == '1') {
        //             // cout << "i=" << i << ", j=" << j << endl;
        //             int k = states[i+1][j+1];
        //             bool col_ok = true, row_ok = true;
        //             for (int p=i+1; p <= i+k; p++) {
        //                 if (p > n-1 || matrix[p][j] != '1') {
        //                     row_ok = false;
        //                     break;
        //                 };
        //             }
        //             for (int p=j+1; p <= j+k; p++) {
        //                 if (p > m-1 || matrix[i][p] != '1') {
        //                     col_ok = false;
        //                     break;
        //                 };
        //             }
        //             states[i][j] = row_ok && col_ok ? k+1 : 1;
        //             max_len = max(max_len, states[i][j]);
        //         }
                
        //     }
        // }
        // return max_len * max_len;

        // solution two
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size(), max_len = 0;
        vector<vector<int>> states(n, vector<int>(m, 0));
        for (int i=n-1; i>=0; i--) {
            states[i][m-1] = matrix[i][m-1] == '1' ? 1 : 0;
            max_len = max(max_len, states[i][m-1]);
        }
        for (int i=m-1; i>=0; i--) {
            states[n-1][i] = matrix[n-1][i] == '1' ? 1 : 0;
            max_len = max(max_len, states[n-1][i]);
        }

        for (int i=n-2; i>=0; i--) {
            for (int j=m-2; j>=0; j--) {
                if (matrix[i][j] == '1') {
                    // cout << "i=" << i << ", j=" << j << endl;
                    states[i][j] = min(min(states[i+1][j], states[i][j+1]), states[i+1][j+1]) + 1;
                    max_len = max(max_len, states[i][j]);
                }
                
            }
        }
        return max_len * max_len;

    }
};
// @lc code=end

