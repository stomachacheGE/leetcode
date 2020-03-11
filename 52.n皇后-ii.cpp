/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
private:
    bool validPosition(int x, int y, int n,
                        vector<int> rows,
                        vector<int> cols,
                        vector<int> dales,
                        vector<int> hills) {
        return rows[x] + cols[y] + dales[x-y+n-1] + hills[x+y] == 0;
    }
    void backtracking(int row, int n,
                        vector<int>& rows,
                        vector<int>& cols,
                        vector<int>& dales,
                        vector<int>& hills,
                        int& res) {
        if (row > n) {
            return;
        }

        if (row == n) {
            res++;
            return;
        }

        for (int col=0; col< n; col++) { // iterate over col
            if (validPosition(row, col, n, rows, cols, dales, hills)) {
                int x = row, y = col;
                rows[x] = 1;
                cols[y] = 1;
                dales[x-y+n-1] = 1;
                hills[x+y] = 1;
                backtracking(row+1, n, rows, cols, dales, hills, res); 
                rows[x] = 0;
                cols[y] = 0;
                dales[x-y+n-1] = 0;
                hills[x+y] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {

        // backtracking
        int res = 0;
        int row = 0;
        vector<int> rows(n,0), cols(n,0), dales(2*n,0), hills(2*n, 0);
        backtracking(row, n, rows, cols, dales, hills, res); // iterate over row
        return res;

    }
};
// @lc code=end

