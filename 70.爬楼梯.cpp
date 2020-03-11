/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs1(int n) {
        ////////// Solution One ////////////
        // Naive solution, Fibnacci problem, F(n) = F(n-1) + F(n-2)
        // However, this exceeds time limit, since there are a lot
        // of duplicated calculations. For example:
        // F(9) = F(8) + F(7)
        // F(8) = F(7) + F(6)

        // if (n<3) return n;
        // return climbStairs(n-1) + climbStairs(n-2);

        ////////// Solution Two ////////////
        // bottom-up solution
        //Ref.: https://leetcode.com/problems/climbing-stairs/discuss/25609
        if (n < 3) return n;
        int fn_1 = 2, fn_2 = 1, i=3;
        int tmp;
        while (i++ < n) {
            tmp = fn_1;
            fn_1 = fn_2 + fn_1;
            fn_2 = tmp;
        }
        return fn_1 + fn_2;



    }
    int climbStairs(int n) {
        // recursion
        // time limit exceed
        // if (n <= 2) return n;
        // return climbStairs(n-1) + climbStairs(n-2); 

        // dynamic programing
        if (n <= 2) return n;
        int fn_minus_2 = 1, fn_minus_1 = 2, cur = 3, temp;
        while (cur++ <= n) {
            temp = fn_minus_1;
            fn_minus_1 += fn_minus_2;
            fn_minus_2 = temp;
        }
        return fn_minus_1;
        

    }
};
// @lc code=end

