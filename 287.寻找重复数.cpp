/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // solution one
        // ref.:https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/161157
        // 把nums看成是顺序存储的链表，nums中每个元素的值是下一个链表节点的地址
        // 那么如果nums有重复值，说明链表存在环，本问题就转化为了找链表中环的入口节点，因此可以用快慢指针解决
        // int n = nums.size();
        // int slow = 0, fast = 0;
        // while (true) {
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        //     if (slow == fast) break;
        // }

        // fast = 0;
        // while (fast != slow) {
        //     fast = nums[fast];
        //     slow = nums[slow];
        // }
        // return slow;

        // solution one (v2)
        // ref.:https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/
        // binary search，很巧妙的思想
        int size = nums.size();
        int n = size - 1, l = 1, r = n, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            int cnt = 0;
            for (auto &num: nums) {
                if (num <= mid) cnt++;
            }

            if (cnt <= mid) { // must include <, consider nums = [2,2,2,2]
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;


    }
};
// @lc code=end

