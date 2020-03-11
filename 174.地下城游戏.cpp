/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // solution one
        // dynamic programming
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        if (n == 0) return 0;
        // state存储在进入此位置前至少需要多少血才能安全通过这个位置
        vector<vector<int>> state(m, vector<int>(n, 0));
        state[m-1][n-1] = dungeon[m-1][n-1] < 0 ? -dungeon[m-1][n-1]+1 : 1;
        
        // 初始化
        for (int i=m-2; i>=0; i--) {
            if (dungeon[i][n-1] >= 0) {
                state[i][n-1] = max(1, state[i+1][n-1]-dungeon[i][n-1]);
            } else {
                state[i][n-1] = state[i+1][n-1] - dungeon[i][n-1];
            }
        }
        for (int i=n-2; i>=0; i--) {
            if (dungeon[m-1][i] >= 0) {
                state[m-1][i] = max(1, state[m-1][i+1] - dungeon[m-1][i]);
            } else {
                state[m-1][i] = state[m-1][i+1] - dungeon[m-1][i];
            }
        }

        for (int i=m-2; i>=0; i--) {
            for (int j=n-2; j>=0; j--) {
                if (dungeon[i][j] >= 0) {
                    state[i][j] = max(1, min(state[i+1][j]-dungeon[i][j], state[i][j+1]-dungeon[i][j]));
                } else {
                    state[i][j] = min(state[i+1][j]-dungeon[i][j], state[i][j+1]-dungeon[i][j]);
                }
            }
        }
        return state[0][0];

    }
};
// @lc code=end

