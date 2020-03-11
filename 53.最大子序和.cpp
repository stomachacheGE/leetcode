/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
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
    int maxSubArray1(vector<int>& nums) {
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
        int size, res, potential_res;
        size = nums.size();
        res = potential_res = nums[0];
        for (int i=1; i < size; i++) {
            potential_res = max(potential_res+nums[i], nums[i]);
            if (potential_res > res) res = potential_res;
        }
        return res;
    }

    int maxSubArray(vector<int>& nums) {

        // solution one
        // dynamic programming

        int res = INT_MIN, cur = 0;
        for (int i=0; i<nums.size(); i++) {
            cur = max(nums[i], cur+nums[i]);
            res = max(res, cur);
        }
        return res;
    }
};
// @lc code=end

