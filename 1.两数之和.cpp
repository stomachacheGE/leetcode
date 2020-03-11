/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        vector<int> res;
        for (int i=0; i<=nums.size(); i++) {
            if (table.count(target-nums[i])) {
	            res.push_back(table[target-nums[i]]);
                res.push_back(i);
                break;
	        } 
            table[nums[i]] = i;
        }
        return res;  
    }
};
// @lc code=end

