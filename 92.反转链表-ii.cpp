/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween1(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        // 得到区间前后的点，在反转后需要用到
        int counter = 1;
        ListNode* after_interval=NULL;
        ListNode* prev_interval=dummy;
        ListNode* node=head;
        for (; counter <= n; counter++) {
            if (counter + 1 == m) {
                prev_interval = node;
            }
            node = node->next;
        }
        after_interval = node;
        
        // 反转区间
        ListNode* prev = NULL;
        ListNode* curt = prev_interval->next;
        while (curt != after_interval) {
            ListNode* temp = curt->next;
            curt->next = prev;
            prev = curt;
            curt = temp;
        }
        
        // 连接
        prev_interval->next->next = after_interval;
        prev_interval->next = prev;
        
        return dummy->next;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // solution one
        // 不打乱链表结构，只交换值
        // if (!head) return head;
        // ListNode *behind = head, *ahead;
        // int c = 1;
        // while (c++ < m) {
        //     behind = behind->next;
        // }
        // ahead = behind;
        // stack<int> vals;
        // c = m;
        // while (c++ <= n) {
        //     vals.push(ahead->val);
        //     ahead = ahead->next;
        // }
        // while (!vals.empty()) {
        //     behind->val = vals.top();
        //     vals.pop();
        //     behind = behind->next;
        // }
        // return head;

        // solution two 
        // 找到需要反转的区间，反转后再连接
        if (!head) return head;
        ListNode *prev, *after, *nodem, *noden, *node = head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        prev = dummy;
        int c = 1;
        while (c <= n+1) {
            if (c == m - 1) prev = node;
            if (c == m) nodem = node;
            if (c == n) noden = node;
            if (c == n+1) after = node;
            c++;
            if (node) node = node->next;
        }

        // 反转链表
        ListNode *pprev = NULL, *cur = nodem, *temp;
        while (cur != after) {
            temp = cur->next;
            cur->next = pprev;
            pprev = cur;
            cur = temp;
        }

        // 重链接
        nodem->next = after;
        prev->next = noden;
        return dummy->next;
    }
};
// @lc code=end

