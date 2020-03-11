/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {

        // solution one
        // recursive
        // if (!head || !head->next) return head;
        // ListNode *reversed = reverseList(head->next), *node = reversed;
        // while (node->next) {
        //     node = node->next;
        // }
        // node->next = head;
        // head->next = NULL;
        // return reversed;

        // solution two
        // iterative
        if (!head || !head->next) return head;
        ListNode *prev = NULL, *cur = head, *temp;
        while (cur) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;

    }
};
// @lc code=end

