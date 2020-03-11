/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> rule1(81, false), rule2(81, false), rule3(81, false);
        for (int i=0; i<=8; i++) {
            for (int j=0; j<=8; j++) {
                if (board[i][j] == '.') continue;
                int idx1 = i * 9 + board[i][j] - '1';
                int idx2 = j * 9 + board[i][j] - '1';
                int idx3 = ((i / 3) * 3 + j / 3) * 9 + board[i][j] - '1';
                
                if (rule1[idx1] || rule2[idx2] || rule3[idx3]) {
                    return false;
                }
                rule1[idx1] = true;
                rule2[idx2] = true;
                rule3[idx3] = true;
            }
        }
        return true;

    }
};
// @lc code=end

