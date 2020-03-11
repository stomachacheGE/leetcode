/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        // solution one
        // dynamic programming
        // 从右下角开始网上，每个状态包含以它为起点的矩形的长宽
        // 不能通过所有case，如[["1","1","0","1"],["1","1","0","1"],["1","1","1","1"]]
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<pair<int,int>>> table(m, vector<pair<int,int>>(n, make_pair(0,0)));
        if (matrix.back().back() == '1') table.back().back() = make_pair(1, 1);
        for (int i=m-2; i>=0; i--) {
            if (matrix[i][n-1] == '0') continue;
            table[i][n-1] = make_pair(1, table[i+1][n-1].second+1);
        }
        for (int i=n-2; i>=0; i--) {
            if (matrix[m-1][i] == '0') continue;
            table[m-1][i] = make_pair(table[m-1][i+1].first+1, 1);
        }

        for (int i=m-2; i>=0; i--) {
            for (int j=n-2; j>=0; j--) {
                if (matrix[i][j] == '0') continue;
                int p, cur = 0;
                
                // right
                bool right = true;
                p = table[i][j+1].second;
                while (--p > 0) {
                    if (matrix[i+p][j] == '0') right = false;
                }
                if (right && (table[i][j+1].first+1) * table[i][j+1].second > cur) {
                    table[i][j] = make_pair(table[i][j+1].first+1, table[i][j+1].second);
                    cur = table[i][j].first * table[i][j].second;
                }
                // down
                bool down = true;
                p = table[i+1][j].first;
                while (--p > 0) {
                    if (matrix[i][j+p] == '0') down = false;
                }
                if (down && table[i+1][j].first * (table[i+1][j].second+1) > cur) {
                    table[i][j] = make_pair(table[i+1][j].first, table[i+1][j].second+1);
                    cur = table[i][j].first * table[i][j].second;
                }
                // right-down
                bool right_down = true;
                p = table[i+1][j+1].first;
                int q = table[i+1][j+1].second;
                while (--p > 0) {
                    if (matrix[i][j+p] == '0') right_down = false;
                }
                while (right_down && --q > 0) {
                    if (matrix[i+q][j] == '0') right_down = false;
                }
                if (right_down && (table[i+1][j+1].first+1) * (table[i+1][j+1].second+1) > cur) {
                    table[i][j] = make_pair(table[i+1][j+1].first+1, table[i+1][j+1].second+1);
                }
            }
        }

        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                cout << "i=" << i << ", j=" << j << endl;
                cout << table[i][j].first << " " << table[i][j].second << endl;
                res = max(res, table[i][j].first * table[i][j].second);
            }
        }
        return res;


    }
};
// @lc code=end

