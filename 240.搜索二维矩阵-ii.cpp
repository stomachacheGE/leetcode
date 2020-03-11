/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
private:
    bool searchMatrix(vector<vector<int>>& matrix, int target, int l, int r, int u, int d) {
        cout << "l=" << l << ", r=" << r << ", u=" << u << ", d=" << d << endl;
        if (l > r || u > d) return false; // this is necessary 

        if (l == r && u == d) {
            return matrix[u][l] == target;
        }

        int my = l + (r - l) / 2;
        int mx = u + (d - u) / 2;
        if (matrix[mx][my] < target) {
            return searchMatrix(matrix, target, my+1, r, u, d) || 
                   searchMatrix(matrix, target, l, my, mx+1, d);
        } else {
            return searchMatrix(matrix, target, l, my, u, d) ||
                   searchMatrix(matrix, target, l+1, r, u, mx);
        }   

    }

    bool searchRowAndCol(vector<vector<int>>& matrix, int target, int i, int m, int n) {
        int l = i, r = n - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (i < m && mid < n && matrix[i][mid] < target) { // check boundary
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l < n && i < m && matrix[i][l] == target) return true; // check boundary
        int u = i, d = m - 1;
        while (u < d) {
            mid = u + (d - u) / 2;
            if (mid < m && i < n && matrix[mid][i] < target) { // check boundary
                u = mid + 1;
            } else {
                d = mid;
            }
        }
        return u < m && i < n ? matrix[u][i] == target : false; // check boundary
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // solution one
        // 思路错误，会导致情况极其复杂
        // int m = matrix.size();
        // if (m == 0) return false;
        // int n = matrix[0].size();
        // if (n == 0) return false;

        // return searchMatrix(matrix, target, 0, n-1, 0, m-1);

        // solution two
        // Ref.:https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/
        // 遍历对角元素，并分别在对角元素的行或者列上进行二分查找
        // 复杂度为O(logn!) (很奇怪的复杂度)
        // int m = matrix.size();
        // if (m == 0) return false;
        // int n = matrix[0].size();
        // if (n == 0) return false;

        // for (int i=0; i<m; i++) {
        //     if (searchRowAndCol(matrix, target, i, m, n)) return true;
        // }
        // return false;

        // solution three
        // Ref.:https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/
        // 从左下角/右上角开始检查
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int i = m-1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] < target) {
                j++;
            } else if (matrix[i][j] > target) {
                i--;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

