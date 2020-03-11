/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        // solution one
        // dynamic programming
        // 状态转移不是最有，只能过540/588，超时
        // if (n == 1) return 1;
        // vector<int> states(n+1, 1);
        // for (int i=1; i<=n; i++) states[i] = i;
        // for (int i=2; i<=n; i++) {
        //     if (int(sqrt(i)) * int(sqrt(i)) == i) {
        //         states[i] = 1;
        //         continue;
        //     }
        //     for (int j=1; j<=i/2+1; j++) {
        //         states[i] = min(states[j]+states[i-j], states[i]);
        //     }
        // }
        // return states[n];

        // solution two
        // ref.:https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/244753
        if (n == 1) return 1;
        vector<int> states(n+1, 0);
        for (int i=1; i<=n; i++) states[i] = i;
        for (int i=2; i<=n; i++) {
            for (int j=1; j*j<=i; j++) {
                // 这个数的完全平方数分解必定是某个完全平方数加上另一个数构成
                states[i] = min(states[i-j*j]+1, states[i]);
            }
        }
        return states[n];
    }
};
// @lc code=end

