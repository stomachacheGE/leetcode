/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
private:
    vector<pair<int,int>> getValidNeighbors(int i, int j, int N, int M, vector<vector<char>>& grid) {
        vector<pair<int,int>> res;
        if (i-1>=0 && grid[i-1][j] == '1') res.push_back(make_pair(i-1, j));
        if (i+1< N && grid[i+1][j] == '1') res.push_back(make_pair(i+1, j));
        if (j-1>=0 && grid[i][j-1] == '1') res.push_back(make_pair(i, j-1));
        if (j+1< M && grid[i][j+1] == '1') res.push_back(make_pair(i, j+1));
        return res;
    }
    
    void floodFill(int i, int j, int N, int M, vector<vector<char>>& grid) {
        
        // cout << "starting from (" << i << ", " << j << "}" << endl;
        grid[i][j] = '0';
        
        queue<pair<int, int>> q;
        q.push(make_pair(i,j));
        
        // bfs
        // int p, q;
        vector<pair<int,int>> neighbors;
        while (!q.empty()) {
            pair<int, int> ele = q.front();
            q.pop();
            neighbors = getValidNeighbors(ele.first, ele.second, N, M, grid);
            for (auto &neighbor: neighbors) {
                grid[neighbor.first][neighbor.second] = '0';
                q.push(neighbor);
                // cout << " '" << neighbor.first << " " << neighbor.second << "'";
            }
            // cout << endl;
        }
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands1(vector<vector<char>>& grid) {
        int res = 0;
        int rows = grid.size();
        if (rows == 0) return res;
        int cols = grid[0].size();
        
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    floodFill(i, j, rows, cols, grid);
                }
            }
        }
        return res;
    }

    int numIslands(vector<vector<char>>& grid) {

        // 也可以用dfs
        // ref.:https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
        int res = 0;
        int rows = grid.size();
        if (rows == 0) return res;
        int cols = grid[0].size();
        
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    floodFill(i, j, rows, cols, grid);
                }
            }
        }
        return res;

        // 并查集 (TODO)
        // ref.:https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
    }
};
// @lc code=end

