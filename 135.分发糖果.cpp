/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {

        // solution one
        if (ratings.empty()) return 0;
        if (ratings.size() == 1) return 1;
        int res = 0;
        vector<int> candies(ratings.size(), 0);
        candies[0] = 1;
        // 从前往后，只要比前一个同学得分高
        // 则糖果数是前一个同学糖果数加一
        // 否则糖果数为1
        for (int i=1; i<ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) { 
                candies[i] = candies[i-1] + 1;
            } else {
                candies[i] = 1;
            }
        }

        // 从后往前，只要比后一个同学得分高，
        // 这个同学的糖果数是当前糖果数和后一个同学糖果数加一的最大值
        for (int i=ratings.size()-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        for (auto &candy: candies) {
            res += candy;
            // cout << candy << endl;
        }
        return res;

        // solution two
        // https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/
        // o(1)空间复杂度
    }
};
// @lc code=end

