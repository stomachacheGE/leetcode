/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        // solution one (v2)
        if (num == 0 || num == 1) return true;
        int l = 1, r = num/2, mid;
        while (l < r) {
            mid = l + (r - l + 1) / 2;
            // cout << "l=" << l << ", r=" << r << ", mid=" << mid << endl;
            if (mid > num / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l * l == num ? true : false;
    }
};
// @lc code=end

