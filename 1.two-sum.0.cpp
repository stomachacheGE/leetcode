/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.04%)
 * Total Accepted:    1.8M
 * Total Submissions: 4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> num_to_idx;
      vector<int> res;
      
      // first pass to store num to hashmap
      for(int i=0; i<nums.size(); i++) {
	num_to_idx[nums[i]] = i;
      }
      
      // second pass
      for (int i=0; i<nums.size(); i++) {
	int residual = target - nums[i];
	auto find = num_to_idx.find(residual);
        if(find != num_to_idx.end() &&
           find->second != i) {
           res.push_back(i);
	   res.push_back(find->second);
           break;
	}
      }
      return res;    
    }
};
