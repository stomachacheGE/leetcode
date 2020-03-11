/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // solution one
        // naive implementation
        // 能通过所有case， 但是最后一个用例超时了
        // 因为最后一个用例的k=1000
        // if (nums.size() < 2) return false;
        // for (int i=0; i<nums.size(); i++) {
        //     for (int j=1; j<=k; j++) {
        //         if (i+j >= nums.size()) break;
        //         if (abs(long(nums[i+j]) - long(nums[i])) <= long(t)) return true;
        //     }
        // }
        // return false;

        // solution two
        // 优化点在于判断大小为k的滑动窗口收否存在满足条件一(abs(nums[i]-nums[j]) <=t)的数
        // 如果滑动窗口里面是有序的，则可以通过二分查找在logk的时间内找到
        // 利用set(底层是平衡搜索二叉树，红黑数？)来维护窗口k里的数组的有序性
        // https://leetcode-cn.com/problems/contains-duplicate-iii/solution/220-by-ikaruga/
        set<double> _set;
        for (int i=0; i<nums.size(); i++) {
            auto it = _set.lower_bound((double) nums[i] - (double) t);
            if (it != _set.end() && *it <= (double) nums[i] + (double) t) {
                return true;
            }
            _set.insert((double) nums[i]);
            if (_set.size() > k) {
                _set.erase(nums[i-k]);
            }
        }
        return false;
    }
};
// @lc code=end

