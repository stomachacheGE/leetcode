/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> rob_helper(TreeNode* root) {
        vector<int> res {0,0};
        if (!root) return res;
        vector<int> money_left = rob_helper(root->left);
        vector<int> money_right = rob_helper(root->right);
        res[0] = root->val + money_left[1] + money_right[1];
        res[1] = max(money_left[0], money_left[1]) + max(money_right[0], money_right[1]);
        return res;  
    }
public:
    int rob(TreeNode* root) {
        // solution one
        // 递归

        // solution two
        // 递归 + memo (TODO)

        // solution three
        // ref.:https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/
        // rob_helpler返回大小为2的vector， 分别代表打劫这家和不打劫这家时能得到的钱
        vector<int> money = rob_helper(root);
        return max(money[0], money[1]);
    }
};
// @lc code=end

