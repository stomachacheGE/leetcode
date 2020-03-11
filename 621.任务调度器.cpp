/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class myComparision {
public:
    bool operator() (const pair<char, int>& lhs, const pair<char, int>& rhs) {
            return lhs.second < rhs.second;
        }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // solution one
        // 思路错误，能通过16/64
        // 不能通过：["A","A","A","A","A","A","B","C","D","E","F","G"]\n2
        priority_queue<pair<char, int>, vector<pair<char, int>>, myComparision> pq;
        vector<int> counter(26, 0);
        for (auto &c: tasks) {
            counter[c-'A']++;
        }
        for (int i=0; i<26; i++) {
            if (counter[i]) pq.push(make_pair(i+'A', counter[i]));
        }
        
        int res = 0;
        pair<char, int> cur;
        while (!pq.empty()) {
            cur = pq.top();
            cout << "cur=" << cur.first << ", count=" << cur.second << endl;
            pq.pop();
            int available = cur.second * n;
            res += cur.second * (n+1);
            while (available && !pq.empty()) {
                pair<char, int> next = pq.top();
                pq.pop();
                if (available - next.second >= 0) {
                    available -= next.second;
                } else {
                    next.second -= available;
                    available = 0;
                    pq.push(next);
                }
            }
            cout << "available = " << available << endl; ;
            res -= n - (cur.second * n - available) / cur.second;
        }
        return res;

    }
};
// @lc code=end

