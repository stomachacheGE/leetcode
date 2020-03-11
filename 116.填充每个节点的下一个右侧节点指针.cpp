/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
private:
    void connect_helper(Node* root, Node*& leftmost, Node*& rightmost) {
        if (!root) return;
        if (!root->left && !root->right) {
            rightmost = root;
            leftmost = root;
            return;
        }
        root->left->next = root->right;
        Node *lc_l, *lc_r, *rc_l, *rc_r;
        connect_helper(root->left, lc_l, lc_r);
        connect_helper(root->right, rc_l, rc_r);
        lc_r->next = rc_l;
        leftmost = lc_l;
        rightmost = rc_r;
    }

public:
    Node* connect(Node* root) {
        // Solution one
        // Ref.:https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--27/
        // 用三个指针模拟bfs的过程

        // if (root == NULL) return NULL;
        // Node *start = root, *pre = root, *cur = NULL;
        // while (start->left) {
        //     // 到了一层的末尾
        //     if (cur == NULL) {
        //         pre->left->next = pre->right;
        //         // 换行
        //         pre = start->left;
        //         cur = start->right;
        //         start = start->left;
        //     } else {
        //         pre->left->next = pre->right;
        //         pre->right->next = cur->left;
        //         // 向右移动
        //         pre = cur;
        //         cur = cur->next;
        //     }
        // }
        // return root;

        // Solution two
        // Ref.:https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/la-la-lian-jie-fa-by-sorcerer/
        // 拉拉链算法，优美但是不好想到
        // 思路是把二叉树中间拉链拉上，在分别递归左右去拉拉链
        // if (!root) return root;
        // Node * left = root->left;
        // Node * right = root->right;
        // while(left) {
        //     left->next = right;
        //     left = left->right;
        //     right = right->left;
        // }
        // connect(root->left);
        // connect(root->right);
        // return root;

        // Solution three
        // 117题答案
        // if (!root) return root;
        // Node *tail, *cur = root;
        // while (cur) {
        //     Node* dummy = new Node();
        //     tail = dummy;
        //     while (cur) {
                
        //         if (cur->left) {
        //             tail->next = cur->left;
        //             tail = tail->next;
        //         }
        //         if (cur->right) {
        //             tail->next =cur->right;
        //             tail = tail->next;
        //         }
        //         cur = cur->next;
        //     }
        //     cur = dummy->next;
        // }
        // return root;

        // solution one (v2)
        // 递归，找到左子树的最右边结点和右子树的最左边结点
        // 思路错误，不能通过[-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13]
        // if (!root) return NULL;
        // Node* leftmost = NULL, *rightmost = NULL;
        // connect_helper(root, leftmost, rightmost);
        // return root;

        // solution two (v2)
        // 从上往下，从左往右链接
        // 因为上一层已经连好了
        // 所以这一层跨父亲结点的连接可以利用上一层的next指针
        // if (!root) return NULL;
        // Node *start = root, *temp;
        // while (start->left) { // 在倒数第二层停止
        //     temp = start;
        //     while (temp) {
        //         temp->left->next = temp->right;
        //         if (temp->next) temp->right->next = temp->next->left;
        //         temp = temp->next;
        //     }
        //     start = start->left;
        // }
        // return root;

        // solution three (v2)
        // 拉拉链算法
        if (!root) return NULL;
        Node* left = root->left;
        Node* right = root->right;
        while (left) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};
// @lc code=end

