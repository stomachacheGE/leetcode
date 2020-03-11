/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    // 注意此处head必须是指针的引用，因为它的值在递归的时候改变
    TreeNode* sortedListToBST(ListNode*& head, int start, int end) {
        
        if (start > end) {
            return NULL;
        }

        int mid = ( start + end ) / 2;
        TreeNode* left_tree = sortedListToBST(head, start, mid-1);
        TreeNode* node = new TreeNode(head->val);
        head = head->next;
        TreeNode* right_tree = sortedListToBST(head, mid+1, end);

        node->left = left_tree;
        node->right = right_tree;
        return node;
    }
public:
    TreeNode* sortedListToBST1(ListNode* head) {
        // solution one
        // 用快慢指针取链表的中间节点作为根结点
        // 递归构建搜索树
        // 由于链表取中间节点的时间复杂度为O(n)
        // 导致最终算法的复杂度为O(nlogn)
        // 复杂度分析：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/you-xu-lian-biao-zhuan-huan-er-cha-sou-suo-shu-by-/

        // solution two
        // Ref.:https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/you-xu-lian-biao-zhuan-huan-er-cha-sou-suo-shu-by-/
        // 模拟搜索树的中序遍历过程，因为其中序遍历是排序好的序列
        // 方法很巧妙，不容易想到
        // 算法时间复杂度为O(n)
        if (head == NULL) return NULL;
        int counter = 0;
        ListNode* node = head;
        while (node != NULL) {
            counter++;
            node = node->next;
        }
        return sortedListToBST(head, 0, counter-1);

        // solution three
        // ref.:https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/kuai-man-zhi-zhen-di-gui-by-lazycece/
        // 快慢指针+递归（TODO）
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // solution one
        // 先把链表数据存在vector中，然后从vector中恢复二叉搜索树

        // solution two
        // 快慢指针+递归，需要断开链表
        // ref.:https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/kuai-man-zhi-zhen-di-gui-by-lazycece/
        // if (!head) return NULL;
        // if (!head->next) return new TreeNode(head->val);
        // ListNode *slow = head, *fast = head->next, *prev = NULL;
        // while (fast) { 
        //     prev = slow;
        //     slow = slow->next;
        //     fast = fast->next;
        //     if (fast) fast = fast->next;
        // }
        // if (prev) prev->next = NULL;
        // TreeNode* node = new TreeNode(slow->val);
        // node->left = sortedListToBST(head);
        // node->right = sortedListToBST(slow->next);
        // return node;

        // solution three
        // Ref.:https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/you-xu-lian-biao-zhuan-huan-er-cha-sou-suo-shu-by-/
        // 模拟搜索树的中序遍历过程，因为其中序遍历是排序好的序列
        // 方法很巧妙，不容易想到
        // 算法时间复杂度为O(n)
        if (head == NULL) return NULL;
        int counter = 0;
        ListNode* node = head;
        while (node != NULL) {
            counter++;
            node = node->next;
        }
        return sortedListToBST(head, 0, counter-1);


    }

    
};
// @lc code=end

