/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (31.24%)
 * Total Accepted:    374.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        ////////// Solution One //////////
        // 100%, 45.4%
        //Ref.: https://www.geeksforgeeks.org/square-root-of-an-integer/
        // if (x==0 || x==1) return x; 
        // int start = 1, end = x/2, ans;
        // long long mid; // use long long to avoid overflow
        // while(start <= end) {
        //     mid = start + (end - start) / 2;
        //     if (mid*mid == x) return mid;
        //     if (mid*mid < x) {
        //         start = mid + 1;
        //         ans = mid;
        //     } else {
        //         end = mid - 1;
        //     }
        // }
        // return ans;

        /////////// Solution Two //////////
        // Ref.: https://leetcode.com/problems/sqrtx/discuss/25047/A-Binary-Search-Solution/239667
        // [QUOTE]: I think this problem's key point is that we want to find the largest number, which num*num <= x, 
        // therefore we should use the binary search to find the upper bound within the range(1,x).
        // Different people may have their own way handling the boundaries, but I figure we'd 
        // better think clearly what we want to find through binary search.
        // Below is my code, just a typical template of using upper bound of binary search
        // int i = 1;
        // int j = x;
        // int ans = 0;
        // while (i <=j){
        //     int mid = i + (j-i)/2;
        //     // upper bound的形式，因为我们要找的ans要是最接近于x的最大的数，利用upper bound
        //     if (mid <= x/mid){
        //         i = mid +1;
        //         ans = mid;
        //     }
        //     else
        //         j = mid-1;
        // }
        // return ans;

        ////////// Solution Three ////////////
        // Newton's method
        // Ref.: https://leetcode.com/problems/sqrtx/discuss/25255/Newton's-Iterative-Method-in-C++/128081
        if (x < 2) return x;
        int r = x / 2;
        while (r > x/r) {
            r = (r + x/r) / 2;
        }
        return r;
    }
};
