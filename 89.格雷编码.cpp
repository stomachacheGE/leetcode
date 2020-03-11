/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
private:
    void grayCode(int cur, int idx, int n, bool goLeft, int num, vector<int>& res) {
        if (res.size() == num) return;

        if (idx == n) {
            idx -= 2;
            goLeft = !goLeft;
        } else if (idx == -1) {
            idx += 2;
            goLeft = !goLeft;
        }

        cur = cur ^ (1 << idx);
        res.push_back(cur);
        int nextIdx = goLeft ? idx + 1 : idx - 1;
        grayCode(cur, nextIdx, n, goLeft, num, res);
    }

public:
    vector<int> grayCode(int n) {

        // Solution one
        // 自己推倒的方法，有错误
        // 在n=3的时候出错，生成的gray code出现循环
        // vector<int> res;
        // res.push_back(0);
        // if (n == 0) {
        //     return res;
        // }
        // int num = pow(2, n), cur = 0;
        // bool goLeft = true;
        // grayCode(cur, 0, n, goLeft, num, res);
        // return res;

        // solution two
        // Ref.:https://leetcode-cn.com/problems/gray-code/solution/zhu-bu-tui-jin-de-dong-tai-gui-hua-jie-fa-by-kpcod/
        // 动态规划，n+1的格雷码可以由n-1的格雷码按照特定的规矩给出
        vector<int> res {0};
        int cur;
        for (int i=1; i<=n; i++) {
            int num = res.size();
            for (int j=num-1; j>=0; j--) {
                cur = res[j] + (1 << (i-1));
                res.push_back(cur);
            }
        }
        return res;
        
    }
};
// @lc code=end

