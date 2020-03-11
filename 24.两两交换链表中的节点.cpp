/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs1(ListNode* head) {
        // Solution one
        // 不用dummy node话不好将交换的节点和之前的节点连起来
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* node = dummy, *tmp;
        while (node->next && node->next->next) {
            tmp = node->next->next;
            node->next->next = node->next->next->next;
            tmp->next = node->next;
            node->next = tmp;
            node = node->next->next;
        }
        return dummy->next;
    }

    ListNode* swapPairs2(ListNode* head) {
        if (!head) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *behind = head, *ahead = head->next, *temp;
        while (ahead) {
            // exchange
            temp = ahead->next;
            prev->next = ahead;
            ahead->next = behind;
            behind->next = temp;
            // move
            prev = behind;
            behind = prev->next;
            ahead = behind ? behind->next : NULL;
        }
        return dummy->next;
    }

    ListNode* swapPairs(ListNode* head) {
        // solution one
        // if (!head) return head;
        // ListNode* dummy = new ListNode(-1);
        // dummy->next = head;
        // ListNode *prev = dummy, *behind = head, *ahead = head->next;
        // while (ahead) {
        //     // exchange
        //     prev->next = ahead;
        //     behind->next = ahead->next;
        //     ahead->next = behind;
        //     // move
        //     prev = behind;
        //     behind = prev->next;
        //     ahead = behind ? behind->next : NULL;
        // }
        // return dummy->next;

        // solution two
        // recursion
        if (!head || !head->next) return head;
        ListNode* second = head->next;
        head->next = swapPairs(second->next);
        second->next = head;
        return second;
    }
};
// @lc code=end

