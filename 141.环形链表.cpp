/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle1(ListNode *head) {
        
        // solution one
        if (head == NULL) return false;
        ListNode *node1 = head, *node2 = head->next; // has to be next, otherwise will never go into loop
        while (node1 && node2 && node1 != node2) {
            node1 = node1->next;
            node2 = node2->next;
            if (node2) node2 = node2->next;
        }
        return node2 == NULL ? false : true;
    }

    bool hasCycle(ListNode *head) {
        // solution one
        if (!head) return false;
        ListNode *slow = head, *fast = head;
        while (true) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            if (!fast) return false; // has to be if, not else
            if (slow == fast) return true;
        }
        return true;

        // solution two
        // if (head == NULL) return false;
        // ListNode *node1 = head, *node2 = head->next; // has to be next, otherwise will never go into loop
        // while (node2 && node1 != node2) {
        //     node1 = node1->next;
        //     node2 = node2->next;
        //     if (node2) node2 = node2->next;
        // }
        // return node2 == NULL ? false : true;
    }
};
// @lc code=end

