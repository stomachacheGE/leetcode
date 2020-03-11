/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
private:
    bool exist(vector<vector<char>>& board, int i, int j, string word, int idx, int m, int n, vector<vector<bool>>& used) { 
        // 以下推出判断不能过[["a"]]\n"a"的case，需换成第15行
        // if (idx == word.size()) return true;
        // cout << "idx=" << idx << ", i=" << i << ", j=" << j << endl;
        if (board[i][j] != word[idx]) return false;
        if (idx == word.size()-1) return true;
        bool up = false, down = false, right = false, left = false;
        used[i][j] = true;
        if (i>=1 && !used[i-1][j])  up = exist(board, i-1, j, word, idx+1, m, n, used);
        if (up) return true; // for time efficiency
        if (i<m-1 && !used[i+1][j]) down = exist(board, i+1, j, word, idx+1, m, n, used);
        if (down) return true;
        if (j>=1 && !used[i][j-1])  left = exist(board, i, j-1, word, idx+1, m, n, used);
        if (left) return true;
        if (j<n-1 && !used[i][j+1]) right = exist(board, i, j+1, word, idx+1, m, n, used);
        if (right) return true;
        used[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Solution one
        int num = word.size();
        if (num == 0) return true;
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (exist(board, i, j, word, 0, m, n, used)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

