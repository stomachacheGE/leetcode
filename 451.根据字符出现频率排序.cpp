/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        // counter + max_heap
        unordered_map<char, int> counter;
        for (auto &c: s) {
            counter[c]++;
        }

        priority_queue<pair<int, char>> max_heap;
        for (auto &ele: counter) {
            max_heap.push(make_pair(ele.second, ele.first));
        }

        string res;
        while (!max_heap.empty()) {
            pair<int, char> cur = max_heap.top();
            max_heap.pop();
            res.insert(res.end(), cur.first, cur.second);
        }
        return res;

    }
};
// @lc code=end

