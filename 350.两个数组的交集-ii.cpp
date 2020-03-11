/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // solution one
        // use unordered_map to count
        // unordered_map<int, int> counter;
        // for (auto &num: nums1) {
        //     counter[num] += 1;
        // }

        // vector<int> res;
        // for (auto &num: nums2) {
        //     if (counter.find(num) != counter.end()) {
        //         if (counter[num] > 0) res.push_back(num);
        //         counter[num]--;
        //     }
        // }
        // return res;

        // solution two
        // 先排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                res.push_back(nums1[i]);
                i++; 
                j++;
     //         while (i < nums1.size() && nums1[i] == nums1[i-1]) i++;
     //         while (j < nums2.size() && nums2[j] == nums2[j-1]) j++;
            }
        }
        return res;
    }
};
// @lc code=end

