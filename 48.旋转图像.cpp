/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Solution One
        // Ref.:https://leetcode-cn.com/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode/的留言
        // 从最外层向最内层，将每层的第一行的数字旋转四次

        int n = matrix.size(), temp;
        for (int i=0; i<n/2; i++) {
            for (int j=i; j<n-i-1; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }

        // Solution two
        // Ref.:https://leetcode-cn.com/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode
        // 先转置，再对每一行进行翻转
    }
};
// @lc code=end

