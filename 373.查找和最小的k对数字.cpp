/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
class comp {
public:
    bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
        return lhs[0] + lhs[1] < rhs[0] + rhs[1];
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // solution one
        // max heap
        // vector<vector<int>> res;
        // if (k == 0) return res;
        // priority_queue<vector<int>, vector<vector<int>>, comp> heap;
        // for (auto &num1: nums1) {
        //     for (auto &num2: nums2) {
        //         vector<int> cur{num1, num2};
        //         if (heap.size() < k) {
        //             heap.push(cur);
        //             continue;
        //         }
        //         vector<int> top = heap.top();
        //         if (top[0] + top[1] > cur[0] + cur[1]) {
        //             heap.pop();
        //             heap.push(cur);
        //         }
        //     }
        // }
        // while (!heap.empty()) {
        //     res.push_back(heap.top());
        //     heap.pop();
        // }
        // return res;

        // solution two
        // ref.:https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/solution/cong-yi-dao-nan-wei-hu-k-da-xiao-de-zui-xiao-dui-z/
        // 加剪枝，“当前 n1，n2 均大于上一次队列满 k 个时的添加数字对，直接退出本次内层循环。
        // 因为队列满了，就证明我已经拿够了 k 对和最小的数字了，没必要再添加更大的。”
        vector<vector<int>> res;
        if (k == 0) return res;
        priority_queue<vector<int>, vector<vector<int>>, comp> heap;
        int last_num1 = INT_MAX, last_num2 = INT_MAX;
        for (auto &num1: nums1) {
            for (auto &num2: nums2) {
                if (num1 > last_num1 && num2 > last_num2) {
                    continue; // prune
                }
                vector<int> cur{num1, num2};
                if (heap.size() < k) {
                    heap.push(cur);
                    continue;
                }
                vector<int> top = heap.top();
                if (top[0] + top[1] > cur[0] + cur[1]) {
                    heap.pop();
                    heap.push(cur);
                    last_num1 = cur[0];
                    last_num2 = cur[1];
                }
            }
        }
        while (!heap.empty()) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};
// @lc code=end

