/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            // 直接用最大堆
            vector<vector<int>> res;
            if (points.size() == 0 || points[0].size() == 0) return res;
            priority_queue<pair<int, int>> heap;
            for (int i=0; i<points.size(); i++) {
                int x = points[i][0], y = points[i][1];
                int dist = x * x + y * y;
                if (heap.size() < K) {
                    heap.push(make_pair(dist, i));
                } else {
                    int cur_max = heap.top().first;
                    if (dist < cur_max) {
                        heap.pop();
                        heap.push(make_pair(dist, i));
                    }
                }
            }

            while (!heap.empty()) {
                res.push_back(points[heap.top().second]);
                heap.pop();
            }

            return res;
        }
};
// @lc code=end

