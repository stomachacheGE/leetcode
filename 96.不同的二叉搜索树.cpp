/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // solution one
        // Ref.:https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode/
        // dynamic programming
        
        // vector<int> g(n+1, 0);
        // g[0] = 1;
        // for (int i=1; i<=n; i++) {
        //     for (int j=1; j<=i; j++) {
        //         g[i] += g[j-1]*g[i-j];
        //     }
        //     // cout << "i=" << i << ", g[i]=" << g[i] << endl;
        // }
        // return g[n];

        // solution one
        // f(n) = f(0)f(n-1) + f(1)f(n-2) + ... + f(n-2)f(1) + f(n-1)f(0)
        vector<int> states(n+1, 0);
        states[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i-1; j++) {
                states[i] += states[j] * states[i-1-j];
            }
        }
        return states[n];
    }
};
// @lc code=end

