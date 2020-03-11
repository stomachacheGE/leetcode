/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1, i;
        int counter = 1;
        while (true) {
            for (i=c1; i<=c2; i++) res[r1][i] = counter++;
            if (++r1 > r2) break;
            for (i=r1; i<=r2; i++) res[i][c2] = counter++;
            if (--c2 < c1) break;
            for (i=c2; i>=c1; i--) res[r2][i] = counter++;
            if (--r2 < r1) break;
            for (i=r2; i>=r1; i--) res[i][c1] = counter++;
            if (++c1 > c2) break;
        }
        return res;
    }
};
// @lc code=end

