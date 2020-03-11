/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal1(vector<vector<int>>& triangle) {
        vector<vector<int>> dp_table;
        
        // intialization
        for (int i=0; i < triangle.size(); i++) {
            vector<int> level;
            for (int j=0; j < triangle[i].size(); j++) {
                level.push_back(INT_MAX);
            }
            dp_table.push_back(level);
        }
        
        dp_table[0][0] = triangle[0][0];
        for (int i=1; i < triangle.size(); i++) {
            dp_table[i][0] = dp_table[i-1][0] + triangle[i][0];
            dp_table[i][i] = dp_table[i-1][i-1] + triangle[i][i];
        }
        
        // state transfer
        for (int i=2; i < triangle.size(); i++) {
            for (int j=1; j < i; j++) {
                dp_table[i][j] = min(dp_table[i][j], dp_table[i-1][j-1] + triangle[i][j]);
                dp_table[i][j] = min(dp_table[i][j], dp_table[i-1][j] + triangle[i][j]);
            }
        }
        
        // answer
        int res = INT_MAX;
        for (int i=0; i < triangle.size(); i++) {
            res = min(res, dp_table[triangle.size()-1][i]);
        }
        return res;
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        // dynamic programing
        if (triangle.empty() || triangle[0].empty()) return 0;
        int m = triangle.size();
        vector<int> states = vector<int>(m, 0);
        int res = INT_MAX;
        states[0] = triangle[0][0];
        for (int i=1; i<m; i++) {
            int temp, temp1=states[0];
            for (int j=1; j<i; j++) {
                temp = temp1;
                temp1 = states[j];
                states[j] = min(states[j], temp) + triangle[i][j];
            }
            states[0] += triangle[i][0]; // 处理头部
            states[i] = temp1 + triangle[i][i]; // 处理尾部
        }
        for (int i=0; i<m; i++) {
            res = min(res, states[i]);
        }
        return res;
    }
};
// @lc code=end

