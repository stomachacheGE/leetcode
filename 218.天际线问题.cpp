/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        // solution one
        // ref.:https://leetcode-cn.com/problems/the-skyline-problem/solution/218tian-ji-xian-wen-ti-sao-miao-xian-fa-by-ivan_al/
        // 扫描线法 + multiset
        vector<pair<int, int>> bs;
        vector<vector<int>> res;
        multiset<int> heights;

        for (auto b: buildings) {
            bs.push_back(make_pair(b[0], -b[2])); // 左端点加入高度的负值
            bs.push_back(make_pair(b[1], b[2]));
        }

        sort(bs.begin(), bs.end()); // 按照less排序
        int prev = 0, cur = 0;
        heights.insert(0); // 保证最后的关键点是(x,0)

        for (auto b: bs) {
            if (b.second < 0) heights.insert(-b.second);
            else heights.erase(heights.find(b.second)); // 必须用find删除迭代器，不然会删除所有b.second的值，导致结果除 cup
            cur = *heights.rbegin(); // 当前最大的height
            if (cur != prev) {
                res.push_back(vector<int>({b.first, cur}));
                prev = cur;
            }
       }

       return res;

        // solution two
        // divide and conqure (TODO)

    }
};
// @lc code=end

