/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Solution One
        // 从最外层到最内层，把每一层分为四条边，按边打印
        // 注意特殊情况的处理
        // vector<int> res;
        // int m = matrix.size();
        // if (m == 0) return res;
        // int n = matrix[0].size();
        // int rStart, rEnd, cStart, cEnd, i;
        // for (rStart=0; rStart<(m+1)/2; rStart++) {
        //     rEnd = m - rStart - 1;
        //     cStart = rStart;
        //     cEnd = n - cStart - 1;
        //     // cout << "rStart = " << rStart << ", rEnd = " << rEnd << ", cStart = " << cStart << ", cEnd = " << cEnd << endl; 
        //     // 情况特殊处理
        //     if (rStart > rEnd) continue;
        //     else if (cStart > cEnd) continue;
        //     else if (rStart == rEnd) {
        //         for (i=cStart; i<=cEnd; i++) res.push_back(matrix[rStart][i]);
        //     } else if (cStart == cEnd) {
        //         for (i=rStart; i<=rEnd; i++) res.push_back(matrix[i][cStart]);
        //     } else {
        //         for (i=cStart; i<cEnd; i++) res.push_back(matrix[rStart][i]);
        //         for (i=rStart; i<rEnd; i++) res.push_back(matrix[i][cEnd]);
        //         for (i=cEnd; i>cStart; i--) res.push_back(matrix[rEnd][i]);
        //         for (i=rEnd; i>rStart; i--) res.push_back(matrix[i][cStart]);
        //     }
        // }
        // return res;

        // Solution two
        // Ref.:https://leetcode-cn.com/problems/spiral-matrix/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-3/
        // 同样的思路，不过代码更简洁
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        int r1 = 0, r2 = m - r1 -1, c1 = 0, c2 = n - c1 - 1, i;
        while (true) {
            for (i=c1; i<=c2; i++) res.push_back(matrix[r1][i]);
            if (++r1 > r2) break;
            for (i=r1; i<=r2; i++) res.push_back(matrix[i][c2]);
            if (--c2 < c1) break;
            for (i=c2; i>=c1; i--) res.push_back(matrix[r2][i]);
            if (--r2 < r1) break;
            for (i=r2; i>=r1; i--) res.push_back(matrix[i][c1]);
            if (++c1 > c2) break;
        }
        return res;

    }
};
// @lc code=end

