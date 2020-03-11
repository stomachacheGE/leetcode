/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {

        // solution one
        // if (nums.size() == 1) return nums[0];
        // int l = 0, r = nums.size()-1, mid;
        // while (l < r) {
        //     mid = l + (r - l) / 2;
        //     if (nums[l] < nums[r]) return nums[l];
        //     if (nums[l] == nums[r]) {
        //         while (l < r && nums[l] == nums[l+1]) l++;
        //         while (l < r && nums[r] == nums[r-1]) r--;
        //         r--;
        //         // cout << "l=" << l << ", r=" << r << endl;
        //         if (l >= r) break;
        //         continue; // has to continue since the mid is changed
        //     }

        //     if (nums[mid] >= nums[l]) {
        //         l = mid + 1;
        //     } else {
        //         r = mid;
        //     }
        // }
        // return nums[l];

        // solution two
        // ref.:https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/154-find-minimum-in-rotated-sorted-array-ii-by-jyd/
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right -= 1; 
            }
        }
        return nums[left];
    }
};
// @lc code=end

