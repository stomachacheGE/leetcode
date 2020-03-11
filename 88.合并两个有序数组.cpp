/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // solution one
        //将nums1从后往前填充
        m -= 1;
        n -= 1;
        while (m >= 0 && n >=0) {
            if (nums1[m] > nums2[n]) {
                nums1[m+n+1] = nums1[m];
                m--;
            } else {
                nums1[m+n+1] = nums2[n];
                n--;
            }
        }

        while (n >= 0) {
            nums1[n] = nums2[n];
            n--;
        }
    }
};
// @lc code=end

