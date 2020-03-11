/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight1(ListNode* head, int k) {
        // Solution One
        // if (!head) return head;
        // // 统计总个数
        // int n=0;
        // ListNode* node = head;
        // while (node) {
        //     n++;
        //     node = node->next;
        // }

        // k = k % n;
        // if (k == 0) return head;
        // ListNode *ahead = head, *behind = head, *res;
        // // 确定断开点
        // int counter = 0;
        // while (counter++ < k) ahead = ahead->next;
        // while (ahead->next) {
        //     ahead = ahead->next;
        //     behind = behind->next;
        // }
        // // 改变链表结构
        // res = behind->next;
        // behind->next = NULL;
        // ahead->next = head;
        // return res;

        // solution one (v2)
        if (head == NULL) return head;
        int n = 0;
        ListNode* node = head;
        while (node) {
            n++;
            node = node->next;
        }
        k = k % n;
        if (k == 0) return head;
        ListNode* ahead = head, *behind = head, *res;
        int temp = 0;
        while (temp < k) {
            temp++;
            ahead = ahead->next;
        }
        while (ahead->next) {
            ahead = ahead->next;
            behind = behind->next;
        }
        res = behind->next;
        ahead->next = head;
        behind->next = NULL;
        return res;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int num = 0;
        ListNode* node = head;
        while (node) {
            num++;
            node = node->next;
        }
        k = k % num;
        if (k == 0) return head; // this is necessary
        ListNode *behind = head, *ahead = head, *res;
        while (k-- > 0) {
            ahead = ahead->next;
        }
        while (ahead->next) {
            ahead = ahead->next;
            behind = behind->next;
        }
        res = behind->next;
        behind->next = NULL;
        ahead->next = head;
        return res;
    }
};
// @lc code=end

