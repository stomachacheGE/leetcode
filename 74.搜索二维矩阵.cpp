/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
private:
    bool searchMatrix(vector<vector<int>>& matrix,  
        int target, int r0, int r1, int c0, int c1) {

            if (r0 > r1 || c0 > c1) return false;

            int rm = r0 + (r1 - r0) / 2;
            int cm = c0 + (c1 - c0) / 2;

            if (matrix[rm][cm] == target) return true;

            if (matrix[rm][cm] > target) {
                if (r0 == r1) {
                    return searchMatrix(matrix, target, r0, r1, c0, cm-1);
                } else {
                    if (matrix[rm][0] <= target) {
                        return searchMatrix(matrix, target, rm, rm, c0, cm-1);
                    } else {
                        return searchMatrix(matrix, target, r0, rm-1, c0, matrix[0].size()-1);
                    }
                }
            } else {
                if (r0 == r1) {
                    return searchMatrix(matrix, target, r0, r1, cm+1, c1);
                } else {
                    if (matrix[rm][c1] >= target) {
                        return searchMatrix(matrix, target, rm, rm, cm+1, c1);
                    } else {
                        return searchMatrix(matrix, target, rm+1, r1, c0, matrix[0].size()-1);
                    }
                }
            }
        }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Solution one
        // 二分查找的思路，中点为行和列各自的重点
        // 判断中点对应的值和target的大小关系后
        // 将搜索区域分为两部分，一部分还是一个矩阵，另一部分退化为一维数组
        // 注意需要区别在矩阵查找和一维查找
        // int m = matrix.size();
        // if (m == 0) return false;
        // int n = matrix[0].size();
        // return searchMatrix(matrix, target, 0, m-1, 0, n-1);

        // Solution two
        // 将二维数组看作一个一维数组，然后用常规的二分查找
        // 坐标对应关系为：
        // row = idx / n, col = idx % n
    //     int m = matrix.size();
    //     if (m == 0) return false;
    //     int n = matrix[0].size();
    //     int i = 0, j = m * n - 1, row, col, mid;
    //     while (i <= j) {
    //         mid = i + (j - i) / 2;
    //         row = mid / n;
    //         col = mid % n;
    //         if (matrix[row][col] == target) return true;
    //         else if (matrix[row][col] < target) i = mid + 1;
    //         else j = mid - 1;
    //     }
    //     return false;

    //  solution one (v2)
    //  把二维矩阵转换成一维处理
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int num = n * m;
        int i = 0, j = num - 1, mid, p, q;
        while (i < j) {
            mid = i + (j - i) / 2;
            p = mid / n;
            q = mid % n;
            if (matrix[p][q] < target) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return matrix[i/n][i%n] == target ? true : false;
    }
};
// @lc code=end

