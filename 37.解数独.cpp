/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
private:
    bool validNumber(int i, int p, int q, vector<vector<int>>& cols,
                      vector<vector<int>>& rows,
                      vector<vector<int>>& boxes) {
            int box = (p / 3) * 3 + (q / 3);
            return rows[p][i] + cols[q][i] + boxes[box][i] == 0;
        }

    void backtracking(vector<vector<char>>& board, deque<pair<int, int>>& idxs,
                      vector<vector<int>>& cols,
                      vector<vector<int>>& rows,
                      vector<vector<int>>& boxes,
                      bool& found) {
        if (found) return;
        if (idxs.empty()) {
            found = true;
            return;
        }
        pair<int, int> cur = idxs.front();
        int p = cur.first, q = cur.second;
        idxs.pop_front();
        for (int i=0; i<9; i++) {
            if (validNumber(i, p, q, cols, rows, boxes)) {
                board[p][q] = i + '1';
                rows[p][i] = 1;
                cols[q][i] = 1;
                boxes[(p/3)*3+q/3][i] = 1;
                backtracking(board, idxs, cols, rows, boxes, found);
                if (!found) {
                    board[p][q] = '.';
                    rows[p][i] = 0;
                    cols[q][i] = 0;
                    boxes[(p/3)*3+q/3][i] = 0;
                } 
            }
        }
        idxs.push_front(cur);
    }
public:
    void solveSudoku(vector<vector<char>>& board) {

        // backtracking
        // ref.:https://leetcode-cn.com/problems/sudoku-solver/
        vector<vector<int>> rows(9, vector<int>(9, 0)), cols(9, vector<int>(9, 0)), boxes(9, vector<int>(9, 0));
        deque<pair<int, int>> idxs;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') {
                    idxs.push_back(make_pair(i,j));
                } else {
                    int num = board[i][j] - '1';
                    rows[i][num] = 1;
                    cols[j][num] = 1;
                    int box = (i / 3) * 3 + (j / 3);
                    boxes[box][num] = 1;
                }
            }
        }

        bool found = false;
        backtracking(board, idxs, cols, rows, boxes, found);;
    }
};
// @lc code=end

