/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        // solution one
        // binary search, naive 
        // if (x == 0 || x == 1) return x;
        // int left = 0, right = x/2+1; // 对于一个非负数n，它的平方根不会大于（n/2+1
        // while (left < right) {
        //     long mid = left + (right - left) / 2; // 用long，否则mid*mid会overflow
        //     if (mid * mid <= x && (mid+1) * (mid+1) > x) {
        //         return mid;
        //     } else if (mid * mid > x) {
        //         right = mid - 1;
        //     } else {
        //         left = mid + 1;
        //     }
        // } 
        // return left;

        // solution two
        // binary search template
        if (x == 0 || x == 1) return x;
        int left = 0, right = x/2;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (mid > x / mid) { // 用除法避免overflow
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
// @lc code=end

