/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // solution one
        // heap
        vector<int> res(T.size(), 0);
        if (T.empty()) return res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i=0; i<T.size(); i++) {
            while (!q.empty() && T[i] > q.top().first) {
                pair<int, int> cur = q.top();
                q.pop();
                res[cur.second] = i - cur.second;
            }
            q.push(make_pair(T[i], i));
        }
        return res;
    }
};
// @lc code=end

