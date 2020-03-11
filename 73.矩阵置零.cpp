/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Solution one
        // 用两个set分别记录哪些行和哪些列需要置为0
        // 但是额外空间是O(m+n)不符合题目要求

        // Solution two
        // Ref.:https://leetcode-cn.com/problems/set-matrix-zeroes/solution/ju-zhen-zhi-ling-by-leetcode/
        // 不用额外空间，而用第一行和第一列是否为0来标记对应的那一行那一列是否该为0
        // 注意matrix[0][0]既代表第一行，又代表第一列，因此需要一个额外位来区分行或者列
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();

        // 第一列单独处理
        bool firstRow = false;
        for (int i=0; i<n; i++) {
            if (matrix[0][i] == 0) firstRow = true;
        }

        // 用第一行第一列来标记是否置零
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) { // 注意j从0开始，来判断第一列是不是该置零
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 置零
        bool firstColumn = matrix[0][0] == 0;
        for (int i=1; i<n; i++) {
            if (matrix[0][i] == 0) {
                for (int j=1; j<m; j++) matrix[j][i] = 0;
            }
        }
        for (int i=1; i<m; i++) {
            if (matrix[i][0] == 0) {
                for (int j=1; j<n; j++) matrix[i][j] = 0;
            }
        }
        // cout << "firstRow: " << firstRow << ", firstColumn: " << firstColumn << endl;
        // 第一行和第一列必须在其他置零后才能置零
        if (firstRow) {
            for (int i=0; i<n; i++) matrix[0][i] = 0;
        }
        if (firstColumn) {
            for (int i=0; i<m; i++) matrix[i][0] = 0;
        }

    }
};
// @lc code=end

