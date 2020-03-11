/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
private:
    ListNode* cut(ListNode* node, int k) {
        ListNode* res = NULL;
        while (node && k-- > 1) {
            node = node->next;
        }
        if (!node) return res;
        res = node->next;
        node->next = NULL;
        return res;
    }

    ListNode* reverse(ListNode* node, int k) {
        int c = 0;
        ListNode* cur = node;
        while (cur) {
            c++;
            cur = cur->next;
        }
        if (c < k) return node;
        ListNode* prev = NULL, *temp;
        cur = node;
        while (cur) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup1(ListNode* head, int k) {
        if (!head) return head;
        ListNode* dummy = new ListNode(-1), *cur = head, *prev = dummy, *temp;
        while (cur) {
            temp = cur;
            cur = cut(cur, k); // 返回剪切后下一个结点
            prev->next = reverse(temp, k);
            prev = temp;
        }
        return dummy->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // cout << "head=" << head->val <<  endl;
        if (!head) return head;
        int count = 0;
        ListNode* node = head, *remaining;
        while (node && ++count < k) { // note ++count
            node = node->next;
        }
        if (count < k) return head;
        remaining = reverseKGroup(node->next, k);
        node->next = NULL;
        ListNode* res = reverse(head, k);
        head->next = remaining;
        return res;
    }
};
// @lc code=end

