/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Solution one
        // 依然套用三数之和的模版
        // 需要特别注意去重
        vector<vector<int>> res;
        if (nums.size() < 4) return res;

        sort(nums.begin(), nums.end());
        int a=0, b, c, d;
        int sum;
        while (a < nums.size() - 3) {
            // 去重
            while (a > 0 && a < nums.size() - 3 && nums[a] == nums[a-1]) {
                a++;
            }

            b = a + 1;
            while (b < nums.size() - 2) {
                // 去重
                while (b>a+1 && b < nums.size() - 2 && nums[b] == nums[b-1]) {
                    b++;
                }

                c = b+1;
                d = nums.size() - 1;
                while ( c < d ) {
                    sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        res.push_back(vector<int>({nums[a], nums[b], nums[c], nums[d]}));

                        // 去重
                        while (c < d && nums[c+1] == nums[c]) c++;
                        while (c < d && nums[d-1] == nums[d]) d--;
                    }

                    if (sum < target) c++;
                    if (sum > target) d--;
                    if (sum == target) {
                        c++;
                        d--;
                    }
                }
                b++;
            }
            a++;
        }
        return res;
    }
};
// @lc code=end

