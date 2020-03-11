/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        // solution one
        // ref.:https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
        if (head == NULL) return NULL;
        ListNode *node1 = head, *node2 = head;
        while (true) {
            node1 = node1->next;
            node2 = node2->next;
            if (node2) node2 = node2->next;
            if (!node2) return NULL;
            if (node1 == node2) break;
        }

        node2 = head;
        while (node2 != node1) {
            node2 = node2->next;
            node1 = node1->next;
        }
        return node1;
    }
};
// @lc code=end

