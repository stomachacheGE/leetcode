/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
private:
    int countLive(vector<vector<int>>& board, int i, int j) {
        int delta_x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int delta_y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int c = 0, res = 0;
        while (c++ <= 7) {
            int x = i + delta_x[c-1], y = j + delta_y[c-1];
            if (x < 0 || x >= board.size()) continue;
            if (y < 0 || y >= board[0].size()) continue;
            if (board[x][y] <= 1) res += board[x][y];
            else res += board[x][y] - 2;
        }
        return res;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        // solution one
        // 用其他数字编码状态改变：
        // 0～1:2
        // 1～0:3
        if (board.empty() || board[0].empty()) return;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                int num = countLive(board, i, j);
                // cout << "num: " << num << endl;
                if (num < 2) board[i][j] = board[i][j] == 0 ? 0 : 3;
                if (num == 2 || num == 3 && board[i][j] == 1) continue;
                if (num > 3) board[i][j] = board[i][j] == 0 ? 0 : 3;
                if (num == 3 && board[i][j] == 0) board[i][j] = 2;
            }
        }

       for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == 2) board[i][j] = 1;
                if (board[i][j] == 3) board[i][j] = 0;
            }
       }
    }
};
// @lc code=end

