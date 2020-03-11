/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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

class comp {
public:
    bool operator () (const ListNode* node1, const ListNode* node2) {
        return node1->val > node2->val; // 最小堆用>
    }
};

class Solution {

ListNode* merge2lists(ListNode* node1, ListNode* node2) {
        ListNode* dummy = new ListNode(-1), *node = dummy;
        
        while (node1 && node2) {
            if (node1->val < node2->val) {
                node->next = node1;
                node1 = node1->next;
                node = node->next;
                node->next = NULL;
            } else {
                node->next = node2;
                node2 = node2->next;
                node = node->next;
                node->next = NULL;
            }
         }
        
        if (node1) node->next = node1;
        if (node2) node->next = node2;
        
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
        
        if (start == end) return lists[start];
        
        int mid = start + (end - start) / 2;
        ListNode* left  = mergeKLists(lists, start, mid);
        ListNode* right = mergeKLists(lists, mid+1, end);
        
        return merge2lists(left, right);        
    }

public:
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        // Divide and Conqure
        if (lists.size() == 0) return NULL;
        int k = lists.size();
        return mergeKLists(lists, 0, k-1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // solution one
        // 最小堆
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        priority_queue<ListNode*, vector<ListNode*>, comp> min_heap;
        for (auto &node: lists) {
            if (node) min_heap.push(node);
        }
        ListNode* dummy = new ListNode(-1), *node = dummy, *cur;
        while (!min_heap.empty()) {
            cur = min_heap.top();
            min_heap.pop();
            if (cur->next) min_heap.push(cur->next);
            node->next = cur;
            node = node->next;
            node->next = NULL;
        }

        return dummy->next;

    }
};
// @lc code=end

