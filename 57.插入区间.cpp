/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
private:
    int findIdx(vector<vector<int>>& intervals, int num) {

        int l = 0, r = intervals.size(); // 注意r在比最后一个区间还大的时候，可以是intervals.size()
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][0] < num && intervals[mid][1] < num) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int l = newInterval[0], r = newInterval[1];
        int l_idx = findIdx(intervals, l), r_idx = findIdx(intervals, r);
        bool l_in_interval = l_idx >= 0 && l_idx < intervals.size() && l >= intervals[l_idx][0] && l <= intervals[l_idx][1];
        bool r_in_interval = r_idx >= 0 && r_idx < intervals.size() &&r >= intervals[r_idx][0] && r <= intervals[r_idx][1];
        int new_l, new_r;
        // cout << "l_idx=" << l_idx << ", r_idx=" << r_idx << ", l_in_interval=" << l_in_interval << ", r_in_interval=" << r_in_interval;
        vector<int> new_interval;
        if (l_in_interval && r_in_interval) {
            new_l = intervals[l_idx][0];
            new_r = intervals[r_idx][1];
            new_interval = {new_l, new_r};
            intervals.erase(intervals.begin()+l_idx, intervals.begin()+r_idx+1);
            intervals.insert(intervals.begin()+l_idx, new_interval);
        } else if (l_in_interval && !r_in_interval) {
            new_l = intervals[l_idx][0];
            new_r = r;
            new_interval = {new_l, new_r};
            intervals.erase(intervals.begin()+l_idx, intervals.begin()+r_idx);
            intervals.insert(intervals.begin()+l_idx, new_interval);
        } else if (!l_in_interval && r_in_interval) {
            new_l = l;
            new_r = intervals[r_idx][1];
            new_interval = {new_l, new_r};
            intervals.erase(intervals.begin()+l_idx, intervals.begin()+r_idx+1);
            intervals.insert(intervals.begin()+l_idx, new_interval);
        } else {
            new_interval = newInterval;
            intervals.erase(intervals.begin()+l_idx, intervals.begin()+r_idx);
            intervals.insert(intervals.begin()+l_idx, new_interval);
        }
        return intervals;
    }
};
// @lc code=end

