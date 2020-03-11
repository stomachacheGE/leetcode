/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    void helper(TreeNode* root,int level,vector<int>& res){
        if(!root) return;
        if(res.size()==level) res.push_back(root->val);
        helper(root->right,level+1,res);
        helper(root->left,level+1,res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // solution one
        // bfs，输出每层最后一个元素
        // vector<int> res;
        // if (root == NULL) return res;
        // deque<TreeNode*> queue;
        // queue.push_back(root);
        // TreeNode* node;
        // int last_level_counter = 1, cur_level_counter = 0;
        // while (!queue.empty()) {
        //     node = queue.front();
        //     queue.pop_front();
        //     if (node->left) {
        //         queue.push_back(node->left);
        //         cur_level_counter++;
        //     }
        //     if (node->right) {
        //         queue.push_back(node->right);
        //         cur_level_counter++;
        //     }
            
        //     last_level_counter--;
        //     if (last_level_counter == 0) {
        //         res.push_back(node->val);
        //         last_level_counter = cur_level_counter;
        //         cur_level_counter = 0;
        //     }
        // }
        // return res;

        // solution two
        // ref.:https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/liang-chong-jie-ti-fang-fa-di-gui-ji-bai-100he-fei/
        // "递归方法是分别遍历一个节点的右节点和左节点，因为是从右边看过来，
        // 所以我们需要首先遍历右节点。这里有个疑问，当遍历左节点时候，
        // 怎么判定它右边没有其他节点了呢？这里我们用到一个变量level，
        // 对于同一层的节点，如果res数组的大小已经等于level了，
        // 说明右边已经有节点存入数组了，该节点就不用再保存。
        // 一直递归下去就可以得到结果。"
        // vector<int> res;
        // helper(root,0,res);
        // return res;     

        // solution one (v2)
        // bfs, 每次加入每一层最后一个结点
        vector<int> res;
        if (!root) return res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            int num = queue.size();
            while (num-- > 0) {
                TreeNode* node = queue.front();
                queue.pop_front();
                if (num == 0) res.push_back(node->val);
                if (node->left) queue.push_back(node->left);
                if (node->right) queue.push_back(node->right);
            }
        }
        return res;
    }
};
// @lc code=end

