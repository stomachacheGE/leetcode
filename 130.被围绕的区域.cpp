/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
private:
    void fillArea(vector<vector<char>>& board, vector<int> coor, vector<vector<bool>>& change) {
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        visited[coor[0]][coor[1]] = true;
        deque<pair<int, int>> queue;
        queue.push_back(make_pair(coor[0], coor[1]));
        while (!queue.empty()) {
            pair<int, int> cur = queue.back();
            queue.pop_back();
            for (auto &direction: directions) {
                int i = direction[0] + cur.first;
                int j = direction[1] + cur.second;
                if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) continue;
                if (board[i][j] == 'O' && !visited[i][j]) {
                    change[i][j] = false;
                    visited[i][j] = true;
                    queue.push_back(make_pair(i, j)); 
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board, int i, int j) {
        deque<pair<int, int>> queue;
        queue.push_back(make_pair(i, j));
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (!queue.empty()) {
            pair<int, int> cur = queue.back();
            queue.pop_back();
            board[cur.first][cur.second] = '#';
            // cout << "cur (" << cur.first << "," << cur.second << ")" << endl;
            for (auto &direction: directions) {
                int m = direction[0] + cur.first;
                int n = direction[1] + cur.second;
                if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size()) continue;
                if (board[m][n] == '#' || board[m][n] == 'X') continue;
                queue.push_back(make_pair(m,n));
                // cout << "added (" << m << "," << n << ")" << endl;
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#') return;
        if (board[i][j] == 'O') board[i][j] = '#';
        dfs(board, i, j+1);
        dfs(board, i, j-1);
        dfs(board, i+1, j);
        dfs(board, i-1, j);
    }
public:
    void solve(vector<vector<char>>& board) {

        // solution one
        // 非递归bfs, 效率不高，额外存储太大
        // int row = board.size();
        // if (row == 0) return;
        // int col = board[0].size();

        // vector<vector<int>> boundaries;
        // for (int i=0; i<col; i++) boundaries.push_back({0, i});
        // for (int i=0; i<row; i++) boundaries.push_back({i, col-1});
        // for (int i=col-1; i>=0; i--) boundaries.push_back({row-1, i});
        // for (int i=row-1; i>=0; i--) boundaries.push_back({i, 0});
        
        // vector<vector<bool>> change(row, vector<bool>(col, true));
        // for (auto &coor: boundaries) {
        //     if (board[coor[0]][coor[1]] == 'X') continue;
        //     fillArea(board, coor, change);
        // }

        // for (int i=1; i<row-1; i++) {
        //     for (int j=1; j<col-1; j++) {
        //         if (change[i][j]) board[i][j] = 'X';
        //     }
        // }

        // solution two
        // 递归dfs
        // ref.:https://leetcode-cn.com/problems/surrounded-regions/solution/dfs-bfs-bing-cha-ji-by-powcai/
        // int row = board.size();
        // if (row == 0) return;
        // int col = board[0].size();

        // for (int i=0; i < row; i++) {
        //     for (int j=0; j < col; j++) {
        //         if (i == 0 || i == row-1 || j == 0 || j == col-1) {
        //             // cout << "i=" << i << ", j=" << j << endl; 
        //             if (board[i][j] == 'X') continue;
        //             dfs(board, i, j);
        //         }
        //     }
        // }

        // for (int i=0; i<row; i++) {
        //     for (int j=0; j<col; j++) {
        //         if (board[i][j] == '#') board[i][j] = 'O';
        //         else if (board[i][j] == 'O') board[i][j] = 'X';
        //     }
        // }

        // solution three
        // 非递归bfs，答案一的优化
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();

        for (int i=0; i < row; i++) {
            for (int j=0; j < col; j++) {
                if (i == 0 || i == row-1 || j == 0 || j == col-1) {
                    // cout << "i=" << i << ", j=" << j << endl; 
                    if (board[i][j] == 'X') continue;
                    bfs(board, i, j);
                }
            }
        }

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
        // solution four
        // ref.:https://leetcode-cn.com/problems/surrounded-regions/solution/bfsdi-gui-dfsfei-di-gui-dfsbing-cha-ji-by-ac_pipe/
        // 并查集
    }
};
// @lc code=end

