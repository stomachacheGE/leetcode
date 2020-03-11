/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        if (start == end) {
            TreeNode* node = new TreeNode(nums[start]);
            return node;
        }

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        TreeNode* left_child = sortedArrayToBST(nums, start, mid-1);
        TreeNode* right_child = sortedArrayToBST(nums, mid+1, end);
        node->left = left_child;
        node->right = right_child;
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // solution one (v2)
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};
// @lc code=end

