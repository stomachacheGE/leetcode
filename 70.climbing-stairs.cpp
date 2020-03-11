/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (44.08%)
 * Total Accepted:    412.4K
 * Total Submissions: 930.9K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */
class Solution {
public:
    int climbStairs(int n) {
        ////////// Solution One ////////////
        // Naive solution, Fibnacci problem, F(n) = F(n-1) + F(n-2)
        // However, this exceeds time limit, since there are a lot
        // of duplicated calculations. For example:
        // F(9) = F(8) + F(7)
        // F(8) = F(7) + F(6)

        // if (n<3) return n;
        // return climbStairs(n-1) + climbStairs(n-2);

        ////////// Solution Two ////////////
        // 100%, 43.78%
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
};
