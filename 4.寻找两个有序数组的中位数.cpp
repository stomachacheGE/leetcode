/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution {
private:
    int helper(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
        
        int num1, num2, count1, count2;
        count1 = nums1.size() - start1;
        count2 = nums2.size() - start2;
        // exit condition
        if (count1 == 0) {
            return nums2[start2+k-1];
        }
        
        if (count2 == 0) {
            return nums1[start1+k-1];
        }
        
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }

        // try to remove k/2 elements from either nums1 or nums2
        if (count1 >= k/2) {
            num1 = nums1[start1+k/2-1];
        } else {
            num1 = INT_MAX;
        }
        
        if (count2 >= k/2) {
            num2 = nums2[start2+k/2-1];
        } else {
            num2 = INT_MAX;
        }
        
        if (num1 < num2) {
            return helper(nums1, start1+k/2, nums2, start2, k-k/2);
        } else {
            return helper(nums1, start1, nums2, start2+k/2, k-k/2);
        }
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // solution one
        // 递归二分搜索
        // ref.:https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
        int m = nums1.size(), n = nums2.size(), k;
        if ((m + n) % 2 == 1) {
            k = (m + n) / 2 + 1;
            return double(helper(nums1, 0, nums2, 0, k));
        }
        if ((m + n) % 2 == 0) {
            k = (m + n) / 2;
            return (helper(nums1, 0, nums2, 0, k) + helper(nums1, 0, nums2, 0, k+1)) / 2.0;
        }
        
        return 0.0;

        // solution two
        // 非递归二分搜索，需要数学推导 (TODO)
        // ref.:https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/jiang-qi-zhuan-wei-zhao-liang-ge-you-xu-shu-zu-de-/
    
    }
};
// @lc code=end

