/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // solution one
        // naive implementation
        // 从每个加油站出发，看能不能够跑一圈
        // 复杂度O(n)
        if (gas.size() == 0) return -1;
        for (int i=0; i<gas.size(); i++) {
            gas[i] -= cost[i];
        }

        for (int i=0; i<gas.size(); i++) {
            // cout << "start from " << i << endl;
            int remain = 0;
            if (gas[i] < 0) continue;
            int len = 0;
            while (len < gas.size()) {
                remain += gas[(i+len) % gas.size()];
                len++;
                // cout << "forward " << len << " times, remain=" << remain << endl;
                if (remain < 0) break;
            }
            if (remain >= 0) return i;
        }
        return -1;

        // solution two
        // Ref.:https://leetcode-cn.com/problems/gas-station/solution/jia-you-zhan-by-leetcode/
        // 复杂度O(n) (TODO)
        
    }
};
// @lc code=end

