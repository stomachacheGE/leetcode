/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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
class Solution {
public:
    void deleteNode1(ListNode* node) {
        
        // 把此结点的下一个结点的值复制过来
        node->val = node->next->val;
        node->next = node->next->next;
        
    }

    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};
// @lc code=end

