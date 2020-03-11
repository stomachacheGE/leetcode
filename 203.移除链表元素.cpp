/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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

    ListNode* removeElements1(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *curt = head;
        while (curt) {
            if (curt->val == val) {
                prev->next = curt->next;
                curt = curt->next;
                continue;
            }
            curt = curt->next;
            prev = prev->next;
        }
        return dummy->next;
    }

    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(-1), *node = dummy;
        dummy->next = head;

        while (node && node->next) {
            if (node->next->val == val) {
                node->next = node->next->next;
                continue;
            }
            node = node->next;
        }
        return dummy->next;

    }
};
// @lc code=end

