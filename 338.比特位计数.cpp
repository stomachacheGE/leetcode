/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        if (num==0) return vector<int>{0};
        if (num==1) return vector<int>{0,1};
        vector<int> res{0,1};
        int cur_level = 1;
        for (int i=2; i<=num; i++) {
            if (i == cur_level*2) {
                cur_level *= 2;
            }
            res.push_back(1+res[i-cur_level]);
        }
        return res;
    }
};
// @lc code=end

