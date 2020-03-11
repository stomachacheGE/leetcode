/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Solution one
        // 首先根据每个区间的左边界对区间进行排序
        // 然后将区间从左向右合并
        // 注意到，合并过程中，区间只有可能和其前面第一个区间合并
        int num = intervals.size();
        vector<vector<int>> res;
        if (num == 0) return res;
        if (num == 1) return intervals;
    
        map<int, vector<int>> table;
        for (auto &interval: intervals) {
            auto found = table.find(interval[0]);
            if (found != table.end()) {
                table[interval[0]][1] = max(interval[1], table[interval[0]][1]);
            } else {
                table[interval[0]] = interval;
            }
        }

        // 注意map的iterator不能用+1
        // Ref.:https://stackoverflow.com/questions/17484354/why-cant-i-do-stdmap-begin-1
        auto cur = table.begin(), next = ++table.begin(); 
                                              
        while (next != table.end()) {
            if ((next->second)[0] <= (cur->second[1])) {
                (next->second)[0] = (cur->second)[0];
                (next->second)[1] = max(cur->second[1], next->second[1]);
            } else {
                res.push_back(cur->second);
            }
            cur++;
            next++;
        }
        res.push_back(cur->second);
        return res;

        // Solution two
        // 区间排序不用map而用自定义的sort compare
        // Ref.:https://leetcode-cn.com/problems/merge-intervals/solution/qu-jian-pai-xu-zai-he-bing-by-xuqnqn/
        // auto cmp = [](vector<int> &a, vector<int> &b) {return a[0] < b[0];};
        // sort(intervals.begin(), intervals.end(), cmp);
        
    }
};
// @lc code=end

