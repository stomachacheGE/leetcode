/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // solution one
        // binary search
        // 因为最终答案n-l的取值范围为0~n
        // 因此右边界是n而不是n-1
        int n = citations.size();
        if (n == 0) return 0;
        int l = 0, r = n, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (citations[mid] < n - mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return n - l;
    }
};
// @lc code=end

