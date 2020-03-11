/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
private:
    bool validPosition(int x, int y, int n,
                        vector<int> rows,
                        vector<int> cols,
                        vector<int> dales,
                        vector<int> hills) {
        // return rows[x] + cols[y] + dales[x-y+n-1] + hills[x+y] == 0;
        return cols[y] + dales[x-y+n-1] + hills[x+y] == 0;
    }
    void backtracking(int row, int n, vector<string>& cur, 
                        vector<vector<string>>& res,
                        vector<int>& rows,
                        vector<int>& cols,
                        vector<int>& dales,
                        vector<int>& hills) {
        if (row > n) {
            return;
        }

        if (row == n) {
            res.push_back(cur);
            return;
        }

        for (int col=0; col< n; col++) { // iterate over col
            if (validPosition(row, col, n, rows, cols, dales, hills)) {
                int x = row, y = col;
                cur[x][y] = 'Q';
                rows[x] = 1;
                cols[y] = 1;
                dales[x-y+n-1] = 1;
                hills[x+y] = 1;
                backtracking(row+1, n, cur, res, rows, cols, dales, hills); 
                cur[x][y] = '.';
                rows[x] = 0;
                cols[y] = 0;
                dales[x-y+n-1] = 0;
                hills[x+y] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {

        // backtracking
        vector<vector<string>> res;
        string row_;
        for (int i=0; i<n; i++) row_ += ".";
        vector<string> cur(n, row_);
        int row = 0;
        vector<int> rows(n,0), cols(n,0), dales(2*n,0), hills(2*n, 0);
        // 其实没必要传入cur,只需要记录每行对应的Q的col位置就可以
        // 甚至rows也可以不要
        backtracking(row, n, cur, res, rows, cols, dales, hills); // iterate over row
        return res;

    }
};
// @lc code=end

