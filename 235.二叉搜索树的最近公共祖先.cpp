/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    void lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q,
                              bool& has_p, bool& has_q, TreeNode*& res) {
        if (!root) return;
        bool l_has_p = false, r_has_p = false, l_has_q = false, r_has_q = false;
        lowestCommonAncestor(root->left, p, q, l_has_p, l_has_q, res);
        lowestCommonAncestor(root->right, p, q, r_has_p, r_has_q, res);
        if (root == p && (l_has_q || r_has_q) && res == NULL) res = root;
        if (root == q && (l_has_p || r_has_p) && res == NULL) res = root;
        if ((l_has_q || r_has_q) && (l_has_p || r_has_p) && res == NULL) res = root;
        if (root == p || l_has_p || r_has_p) has_p = true;
        if (root == q || l_has_q || r_has_q) has_q = true;
        
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // solution one (v2)
        // 后续遍历，看前面是否已经遍历到了p,q
        // 没有充分用树是二叉搜索树的性质
        // TreeNode* res = NULL;
        // bool has_p = false, has_q = false;
        // lowestCommonAncestor(root, p, q, has_p, has_q, res);
        // return res;

        // solution two (v2)
        // ref.:https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian--2/
        if (!root) return root;
        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};
// @lc code=end

