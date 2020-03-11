/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (35.62%)
 * Total Accepted:    362.7K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        ////////// Solution One //////////
        // int total = m + n;
        // while (n-1>=0 || m-1>=0) {
        //     if      (n == 0) nums1[--total] = nums2[--m];
        //     else if (m == 0) nums1[--total] = nums1[--n];
        //     else if (nums1[n-1] > nums2[m-1]) nums1[--total] = nums1[--n];
        //     else    nums1[--total] = nums2[--m];
        // }

        ////////// Solution Two //////////
        // Ref.:https://leetcode.com/problems/merge-sorted-array/discuss/29515
        // QUOTE: This code relies on the simple observation that once all of the 
        // numbers from `nums2` have been merged into `nums1`, the rest of the 
        // numbers in `nums1` that were not moved are already in the correct place.

        int i = n - 1, j = m - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }

};
