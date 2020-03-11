/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    void dfs(TreeNode* node, int cur_level, int& level, int& leaf) {
        if (node == NULL) return;
        if (cur_level > level) level = cur_level;
        if (cur_level == level && node->left == NULL && node->right == NULL) leaf++;

        if (node->left) dfs(node->left, cur_level+1, level, leaf);
        if (node->right) dfs(node->right, cur_level+1, level, leaf);
    }

    int dfs1(TreeNode* node) {
        if (node == NULL) return 0;
        return dfs1(node->left) + dfs1(node->right) + 1;
    }

    bool exists(TreeNode* node, int target, int right) {
        int left = 0, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (mid < target) {
                left = mid + 1;
                if (node) node = node->right;
            } else {
                right = mid;
                if (node) node = node->left;
            }
        }
        return node != NULL;
    }

    bool exists1(TreeNode* node, int target, int num) {
        int l = 0, r = num, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (!node) return false;

            if (mid < target) {
                node = node->right;
                l = mid + 1;
            } else {
                node = node->left;
                r = mid;
            }
        }
        return node != NULL; // need to check node here
    }
public:
    int countNodes(TreeNode* root) {
        // solution one
        // 分别计算树的高度和叶子数量
        // 实际上，每个节点的都会遍历一次，所以复杂度是O(n)
        // if (root == NULL) return 0;
        // int level = 0, leaf = 0;
        // dfs(root, 1, level, leaf);
        // // cout << "level=" << level << ", leaf=" << leaf << endl;
        // return pow(2, level-1) - 1 + leaf;

        // solution two
        // 复杂度O(n)不过更好看的写法
        // return dfs1(root);

        // solution three
        // ref.:https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/wan-quan-er-cha-shu-de-jie-dian-ge-shu-by-leetcode/
        // 先计算树的高度，然后用二分查找判断最后一层的每个节点是否存在
        // 复杂度为O(h**2)
        // if (root == NULL) return 0;
        // int depth = 0, leaf = 0;
        // TreeNode* node = root;
        // while (node) {
        //     depth++;
        //     node = node->left;
        // }
        // int last_level_num = pow(2, depth-1);
        // int left = 0, right = last_level_num - 1, mid;
        // while (left < right) {
        //     mid = left + (right - left + 1) / 2;
        //     if (!exists(root, mid, last_level_num-1)) {
        //         right = mid - 1;
        //     } else {
        //         left = mid;
        //     }
        // }
        // // cout << "depth=" << depth << ", left=" << left;
        // return pow(2, depth-1) + left;

        // solution one (v2)
        // if (root == NULL) return 0;
        // int depth = 0;
        // TreeNode* node = root;
        // while (node) {
        //     depth++;
        //     node = node->left;
        // }

        // int l = 0, r = pow(2, depth - 1) - 1, mid;
        // // 应该去找最后一个存在的结点，而不是去找第一个不存在的结点
        // // 在最后一排也是满的情况下，第一个不存在的结点不好定义
        // while (l < r) {
        //     mid = l + (r - l + 1) / 2;
        //     if (!exists1(root, mid, pow(2, depth - 1)-1)) {
        //         r = mid - 1;
        //     } else {
        //         l = mid;
        //     }
        // }
        // // cout << "depth=" << depth << ", l=" << l;
        // return pow(2, depth - 1) + l;

        // solution one (v3)
        if (root == NULL) return 0;
        int depth = 0;
        TreeNode* node = root;
        while (node) {
            depth++;
            node = node->left;
        }

        int l = 1, r = pow(2, depth - 1), mid;
        // 找第一个不存在的结点
        while (l < r) {
            mid = l + (r - l) / 2;
            if (exists1(root, mid, pow(2, depth - 1)-1)) {
                l = mid +1;
            } else {
                r = mid;
            }
        }
        // cout << "depth=" << depth << ", l=" << l;
        return pow(2, depth - 1) + l - 1;

    }
};
// @lc code=end

