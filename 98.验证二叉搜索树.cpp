/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* node, long& max_, long& min_) {
        if (node == NULL) {
            max_ = LONG_MIN;
            min_ = LONG_MAX;
            return true;
        }

        long left_max, left_min, right_max, right_min;
        bool left_valid = isValidBST(node->left, left_max, left_min);
        if (node->val <= left_max) return false;
        bool right_valid = isValidBST(node->right, right_max, right_min);
        if (node->val >= right_min) return false;
        max_ = max(long(node->val), right_max); // use max for NULL node
        min_ = min(long(node->val), left_min);
        return left_valid && right_valid;

    }
public:
    bool isValidBST(TreeNode* root) {

        // solution one (v2)
        // if (root == NULL) return true;
        // long max = root->val, min = root->val; // use long for case [INT_MAX]
        // return isValidBST(root, max, min);

        // solution two (v2)
        // ref.:https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-by-leetcode/
        // 迭代法中序遍历，每到一个元素判断是不是比前一个元素大
        if (root == NULL) return true;
        stack<TreeNode*> s;
        TreeNode* node = root;
        long prev = LONG_MIN;
        while (node!=NULL || !s.empty()) {

            while (node) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            if (node->val <= prev) return false;
            prev = node->val;
            node = node->right;
        }
        return true;
    }
};
// @lc code=end

