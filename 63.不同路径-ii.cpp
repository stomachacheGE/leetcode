/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
        // intialization
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (m == 0 && n == 0) return 0;
        vector<vector<long>> states(m, vector<long>(n, 0));
        for (int i=0; i<m; i++) {
            if ( obstacleGrid[i][0] == 1) break;
            states[i][0] = 1;
        }
        for (int j=0; j<n; j++) {
            if ( obstacleGrid[0][j] == 1) break;
            states[0][j] = 1;
        }
        
        // state transfer
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    states[i][j] = 0;
                } else {
                    // cout << "i:" << i << " ,j:" << j << endl;
                    states[i][j] = states[i-1][j] + states[i][j-1];
                }
            }
        }
        
        return states[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        // solution one
        // dynamic programing
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<long>> table(m, vector<long>(n, 0));
        for (int i=0; i<n; i++) {
            table[0][i] = obstacleGrid[0][i] ? 0 : 1;
            if (obstacleGrid[0][i]) break;
        }
        for (int i=0; i<m; i++) {
            table[i][0] = obstacleGrid[i][0] ? 0 : 1;
            if (obstacleGrid[i][0]) break;
        }

        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                table[i][j] = obstacleGrid[i][j] ? 0 : table[i-1][j] + table[i][j-1];
            }
        }
        return int(table.back().back());

        // solution two
        // dp, 用obstaclGrid代替dp table
    }
};
// @lc code=end

