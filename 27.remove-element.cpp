/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element/description/
 *
 * algorithms
 * Easy (44.41%)
 * Total Accepted:    406.3K
 * Total Submissions: 914.7K
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array nums and a value val, remove all instances of that value
 * in-place and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [3,2,2,3], val = 3,
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,1,2,2,3,0,4,2], val = 2,
 * 
 * Your function should return length = 5, with the first five elements of nums
 * containing 0, 1, 3, 0, and 4.
 * 
 * Note that the order of those five elements can be arbitrary.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeElement(nums, val);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // (Naive) Solution One
        // Behind points to the element that is equal to value,
        // and then use a while loop to make ahead find the element 
        // that is not equal to value. Exchange these two when the 
        // requirement is met.  
        // Used while loop inside for, NOT elegant.

        // int behind = 0;
        // int ahead = 0;
        // for (; ahead < nums.size(); behind++) {
        //     if (nums[behind] != val) {
        //         ahead++;
        //         continue;
        //     }
        //     while (ahead < nums.size() && nums[ahead] == val) ahead++;
        //     if (ahead == nums.size()) break;
        //     else swap(nums, behind, ahead);
        // }
        // return behind;

        // Solution Two
        // A pointer runs forward to find element that is equal to value,
        // Another pointer runs backward to find element that is not equal.
        // Exchange when requirement is met. 
        // TOO MANY while loops used, NOT elegant. And it's annoying to 
        // check boudary conditions.

        // if (nums.size() == 0) return 0;
        // int forward = 0;
        // int backward = nums.size() - 1;
        // while (forward <= backward) {
        //     while (forward < nums.size() && nums[forward] != val) forward++;
        //     while (backward >= 0 && nums[backward] == val) backward--;
        //     if (forward < backward) swap(nums, forward++, backward--);
        // }
        // return forward;

        // Solution Three (From Solution)
        // A more elegant version of Solution one.
        // The idea is the same as Solution one, but we don't use while loop. 
        // Instead, extra unnecessary movements of the same element will 
        // be introducted.
        // int behind = 0;
        // int ahead = 0;
        // for (; ahead < nums.size(); ahead++) {
        //     if (nums[ahead] != val) {
        //         nums[behind++] = nums[ahead];
        //     }
        // }
        // return behind;

        // Solution Four (From Solution - Two pointer)
        // This solution deals with the unnecessary elmement movements in Solution Three. 
        // Transversing from the first element, and when we encouter an element with value,
        // we swap it the with last elment and decrease the size of nums by 1. What if the 
        // last element is also equal to value? No worries, we will check it in the next 
        // iteration.

        // if (nums.size() == 0) return 0;
        int i = 0;
        int n = nums.size();
        // while (i < n-1) {
        while (i < n) {
            if (nums[i] == val) {
                // swap(nums, i, n-1);
                nums[i] = nums[n-1];
                n--;
            } 
            else i++;
        }
        // return nums[i]==val ? i : i+1;
        return n;
    }

private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
};
