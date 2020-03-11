/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode* root, int cur, int sum) {
        if (!root) return 0;
        cur += root->val;
        int res = 0;
        if (cur == sum) res++;
        res += pathSum(root->left, cur, sum);
        res += pathSum(root->left, 0, sum);
        res += pathSum(root->right, cur, sum);
        res += pathSum(root->right, 0, sum);
        return res;
    }

    int pathSumIncludeRoot(TreeNode* root, int cur, int sum) {
        if (!root) return 0;
        int res = 0;
        cur += root->val;
        if (cur == sum) res++;
        res += pathSumIncludeRoot(root->left, cur, sum);
        res += pathSumIncludeRoot(root->right, cur, sum);
        return res;
    }

public:
    int pathSum(TreeNode* root, int sum) {

        // solution one
        // 会有重复的结果出现，能通过100/126
        // 不能通过[1,null,2,null,3,null,4,null,5]\n
        // if (!root) return 0;
        // return pathSum(root, 0, sum);

        // solution two
        // https://leetcode-cn.com/problems/path-sum-iii/solution/leetcode-437-path-sum-iii-by-li-xin-lei/
        // 分情况为路径可以包含当前结点，也可以不包含当前结点
        if (!root) return 0;
        return pathSumIncludeRoot(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);

    }
};
// @lc code=end

