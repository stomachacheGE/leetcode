/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.49%)
 * Total Accepted:    522.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
private:
    void maxSubArray(vector<int>& nums, int l, int r, int& mx, int& lmx, int& rmx, int& sum) {
        if (l == r) {
            mx = lmx = rmx = sum = nums[l];
            return;
        }

        int mid = l+(r-l)/2;
        int mx1, lmx1, rmx1, sum1;
        int mx2, lmx2, rmx2, sum2;
        maxSubArray(nums, l, mid, mx1, lmx1, rmx1, sum1);
        maxSubArray(nums, mid+1, r, mx2, lmx2, rmx2, sum2);
        mx = max(max(mx1, mx2), rmx1+lmx2);
        lmx = max(lmx1, sum1+lmx2);
        rmx = max(rmx1+sum2, rmx2);
        sum = sum1 + sum2;
    }

public:
    int maxSubArray(vector<int>& nums) {
        ////////// Solution One //////////
        // Use Divide and Conqure - O(nlogn)
        // Ref. 1: https://leetcode.com/problems/maximum-subarray/discuss/20360
        // Ref. 2: https://www.geeksforgeeks.org/sum-of-maximum-of-all-subarrays-divide-and-conquer/
        // The maximum subarray problem can be divided as following:
        // 1) Divide the array into two halves;
        // 2) Return the max of following three:
        //    a) the maximum subarray sum of the left half
        //    b) the maximum subarray sum of the right half
        //    c) the sum of maximum subarray which crosses the middle point
        // For each subarray, these attributes are kept:
        // 1) mx: the maximum subarray sum of this subarray
        // 2) lmx: the largest sum starting from the left most element
        // 3) rmx: the largest sum ending with the right most element
        // 4) sum: the sum of this subarray
        // int size = nums.size();
        // int mx, lmx, rmx, sum;
        // maxSubArray(nums, 0, size-1, mx, lmx, rmx, sum);
        // return mx; 

        ////////// Solution Two //////////
        // Kadane's algorithm - O(n)
        // Ref.:https://www.youtube.com/watch?v=2MmGzdiKR9Y
        int size, res, potential_res;
        size = nums.size();
        res = potential_res = nums[0];
        for (int i=1; i < size; i++) {
            potential_res = max(potential_res+nums[i], nums[i]);
            if (potential_res > res) res = potential_res;
        }
        return res;
    }
};
