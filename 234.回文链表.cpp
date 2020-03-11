/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome1(ListNode* head) {
        // solution one
        // ref.:https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode/
        // 找到中点，原地反转后半部分，再比较
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head; // 注意slow不一定严格返回左中点
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        // reverse
        ListNode* behind = NULL, *ahead = slow, *temp;
        while (ahead) {
            temp = ahead->next;
            ahead->next = behind;
            behind = ahead;
            ahead = temp;
        }

        while (behind) {
            if (behind->val != head->val) return false;
            behind = behind->next;
            head = head->next;
        }
        return true;


        // solution two
        // ref.:https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode/
        // 递归 (TODO)
    }

    bool isPalindrome(ListNode* head) {
        // 找到中点，分成两半，反转第二半，再比较
        if (!head) return true;
        ListNode *slow = head, *fast = head->next, *left, *right;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        right = slow->next;
        slow->next = NULL;
        left = head;

        // reverse right
        ListNode *prev = NULL, *temp;
        while (right) {
            temp = right->next;
            right->next = prev;
            prev = right;
            right = temp;
        }
        right = prev;
        while (left && right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
// @lc code=end

