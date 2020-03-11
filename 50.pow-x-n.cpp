/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
private:
    double myPowRecur(double x, long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        double res = myPowRecur(x, n>>1);
        if (n & 1) {
            return res * res * x;
        } else {
            return res * res;
        }
     }
public:
    double myPow(double x, int n) {
        // solution one 
        // ref.:https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode/

        // if (x == 0) return 0.0;
        // if (n == 0) return 1.0;
        // long N = n;
        // bool minus = false;
        // if (N < 0) {
        //     minus = true;
        //     N = -N;
        // }

        // double res = 1;
        // double cur_product = x;
        // // 快速幂算法
        // while (N) {
        //     if (N & 1) res *= cur_product;
        //     cur_product *= cur_product;
        //     N >>= 1;
        // }
        // return minus ? 1/res : res;

        // soluiton two
        // 递归
        // ref.:https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode/
         if (x == 0) return 0.0;
        if (n == 0) return 1.0;
        long N = n;
        bool minus = false;
        if (N < 0) {
            minus = true;
            N = -N;
        }
        double res = myPowRecur(x, N);
        return minus ? 1/res : res;
    }
};
// @lc code=end

