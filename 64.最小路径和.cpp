/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum1(vector<vector<int>>& grid) {
        
        // intialization
        int m = grid.size(), n = grid[0].size();
        if (m == 0 && n == 0) return 0;
        
        vector<vector<int>> states(m, vector<int>(n, INT_MAX));
        states[0][0] = grid[0][0];
        for (int i=1; i < m; i++) {
            states[i][0] = states[i-1][0] + grid[i][0];
        }
        for (int j=1; j < n; j++) {
            states[0][j] = states[0][j-1] + grid[0][j];
        }
        
        // state transfer
        for (int i=1; i < m; i++) {
            for (int j=1; j < n; j++) {
                states[i][j] = min(states[i][j], states[i][j-1] + grid[i][j]);
                states[i][j] = min(states[i][j], states[i-1][j] + grid[i][j]);
            }
        } 
        
        return states[m-1][n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        // dynamic programming
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        for (int i=1; i<m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        for (int i=1; i<n; i++) {
            grid[0][i] += grid[0][i-1];
        }

        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid.back().back();

    }
};
// @lc code=end

