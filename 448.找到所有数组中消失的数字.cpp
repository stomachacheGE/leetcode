/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        // solution one
        // vector<int> res;
        // int next, temp, n = nums.size();
        // nums.insert(nums.begin(), 0);
        // for (int i=1; i<=n; i++) {
        //     next = nums[i];
        //     while (nums[next]) {
        //         temp = nums[next];
        //         nums[next] = 0;
        //         // cout << "next=" << next << endl;
        //         next = temp;
        //     }
        // }
        // for (int i=1; i<=n; i++) {
        //     if (nums[i]) res.push_back(i);
        // }
        // return res;

        // solution two
        // ref.:ttps://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/cfu-shu-biao-ji-yong-hao-lai-biao-shi-you-mu-you-c/
        // 不用while loop,巧用负数
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;

    }
};
// @lc code=end

