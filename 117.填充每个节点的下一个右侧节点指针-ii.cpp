/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
public:
    Node* connect(Node* root) {

        // solution one
        // 基于116题来该，增加条件判断
        // 过于复杂没有写出来
        // if (!root) return root;
        // Node *start = root, *pre = root, *cur = NULL, *start_temp = NULL;
        // bool has_next_level = true;
        // while (start) {

        //     if (cur == NULL) {
        //         if (pre->left) {
        //             pre->left->next = pre->right;
        //         }

        //         if (!start_temp) {
        //             if (pre->left) {
        //                 start_temp = pre->left;
        //             } else if (pre->right) {
        //                 start_temp = pre->right;
        //             }
        //         }

        //         if (start_temp) {
        //             start = start_temp;
        //             pre = start;
        //             cur = start->next;
        //             start_temp = NULL;
        //         }
        //     } else {
        //         while (!pre->left && !pre->right) {
        //             pre = pre->next;
        //             cur = cur->next
        //         }
        //     }
        // }

        // solution two
        // ref.:https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-28/
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
        // 不用dummy node，代码更复杂
        if (!root) return root;
        Node *start = root, *next_start = NULL, *temp=NULL, *cur=NULL;
        while (start) {
            temp = start;
            next_start = NULL;
            cur = NULL;
            while (temp) {
                if (temp->left) {
                    if (!next_start) next_start = temp->left;
                    if (!cur) {
                        cur = temp->left;
                    } else {
                        cur->next = temp->left;
                        cur = cur->next;
                    }
                }

                if (temp->right) {
                    if (!next_start) next_start = temp->right;
                    if (!cur) {
                        cur = temp->right;
                    } else {
                        cur->next = temp->right;
                        cur = cur->next;
                    }
                }
                temp = temp->next;
            }
            start = next_start;
        }
        return root;
    }
};
// @lc code=end

