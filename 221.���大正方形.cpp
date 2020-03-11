/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        // solution one
        // dynamice programming
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
        //         bool valid = true;
        //         int len = sqrt(table[i-1][j-1]), c = 0;
        //         while (c <= len) {
        //             if (matrix[i][j-c] == '0' || matrix[i-c][j] == '0') {
        //                 valid = false;
        //                 break;
        //             }
        //             c++;
        //         }

        //         if (!valid) {
        //             if (matrix[i][j] == '0') table[i][j] = 0;
        //             else table[i][j] = pow(c, 2);
        //             // cout << "i=" << i << ", j=" << j << ", " << table[i][j] << endl;
        //             continue;
        //         }

        //         table[i][j] = pow(sqrt(table[i-1][j-1])+1, 2);
        //         // cout << "i=" << i << ", j=" << j << ", " << table[i][j] << endl;
        //         res = max(table[i][j], res);
        //     }
        // }
        // return res;

        // solution two
        // ref.:https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode/
        // 状态转移不用那么复杂
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
                if (matrix[i][j] == '1') {
                    table[i][j] = min(min(table[i-1][j], table[i][j-1]), table[i-1][j-1])+1;
                    res = max(table[i][j], res);
                } else {
                    table[i][j] = 0;
                }
                
            }
        }
        return res * res;
    }
};
// @lc code=end

