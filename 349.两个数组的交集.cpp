/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // solution one (v2)
        // 先排序再去重
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        // vector<int> res;
        // int i = 0, j = 0;
        // while (i < nums1.size() && j < nums2.size()) {
        //     if (nums1[i] < nums2[j]) {
        //         i++;
        //     } else if (nums1[i] > nums2[j]) {
        //         j++;
        //     } else {
        //         res.push_back(nums1[i]);
        //         i++; 
        //         j++;
        //         while (i < nums1.size() && nums1[i] == nums1[i-1]) i++;
        //         while (j < nums2.size() && nums2[j] == nums2[j-1]) j++;
        //     }
        // }

        // return res;

        // solution two (v2)
        //Ref.:https://leetcode.com/problems/intersection-of-two-arrays/discuss/81966/Small-C%2B%2B-solution
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto &num: nums2) {
            if (nums_set.erase(num)) {
                res.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end

