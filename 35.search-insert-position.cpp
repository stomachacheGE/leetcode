/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.80%)
 * Total Accepted:    396.6K
 * Total Submissions: 972.1K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        ////////// Solution One/Two //////////
        // Binary search

        int size = nums.size();
        if (size == 0) return 0;
        return searchInsert(nums, target, 0, size-1);

        ////////// Solution Three //////////
        // ref.:https://leetcode.com/problems/search-insert-position/discuss/15101/C%2B%2B-O(logn)-Binary-Search-that-handles-duplicate
        int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] < target) low = mid+1;
            else high = mid-1;
        }

        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
        return low;
    }

private:
    int searchInsert(vector<int>& nums, int target, int left, int right) {

        ////////// Solution One //////////
        // The boudary check is over-complicated, and special attention
        // has to be paied to "return searchInsert(nums, target, left, middle)"
        // (not middle-1)!!!

        // if (left == right) {
        //     if (nums[left] == target) return left;
        //     else if (nums[left] > target) return left;
        //     else return left+1;
        // }

        // int middle = (left + right) / 2;
        // if (nums[middle] == target) return middle;
        // else if (nums[middle] > target) return searchInsert(nums, target, left, middle);
        // else return searchInsert(nums, target, middle+1, right);

        ////////// Solution Two //////////

        if (left > right) return left;

        int middle = (left + right) / 2;
        if (nums[middle] == target) return middle;
        else if (nums[middle] > target) return searchInsert(nums, target, left, middle-1);
        else return searchInsert(nums, target, middle+1, right);
    }
};
