/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates1(ListNode* head) {
        // recursive
        if (head == NULL || head->next == NULL) return head;
        if (head->val == head->next->val) {
            while (head->next && head->val == head->next->val) {
                head->next = head->next->next;
            }
            return deleteDuplicates(head->next);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        // solution one 
        if (!head) return head;
        ListNode *dummy = new ListNode(-1), *behind = dummy, *ahead = head;
        dummy->next = head;
        while (ahead) {
            bool moved = false;
            while (ahead && ahead->next && ahead->val == ahead->next->val) {
                ahead = ahead->next;
                moved = true;
            }
            if (moved) {
                ahead = ahead->next;
                behind->next = ahead;
            } else {
                behind = behind->next;
                ahead = ahead->next;
            }
        }
        return dummy->next; 
    }
};
// @lc code=end

