/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
private:
    bool dfs(int num){
        if(num==0) return true;
        for(int i=0;i<numss.size();i++){
            int m=num-numss[i];
            if(m<0||vis1[i]==1||vis2[m]==1) continue;
            else if(m==0) return true;
            vis1[i]=1;
            vis2[m]=1;
            if(dfs(m)==true) return true;
            vis1[i]=0;
        }
        return false;
    }

public:
    map<int,int>vis1;
    map<int,int>vis2;
    vector<int>numss;

    bool canPartition(vector<int>& nums) {
        // solution one
        // dfs
        // ref.:https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/233444
        // int len=nums.size();
        // numss=nums;
        // int sum=0,ans=0;
        // for(int i=0;i<len;i++){
        //     sum+=nums[i];
        // }
        // if(sum%2==1) return false;
        // return dfs(sum/2);

        // solution two
        // ref.:https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/233444
        // dynamic programming, 背包问题
        int len = nums.size();
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
        }
        if (sum & 1) return false;
        return dp(nums, sum/2);

    }

    bool dp(vector<int>& nums, int target) {

        int len = nums.size();
        // states[i][j]代表前i个数中选任意的数的和能不能为j
        vector<vector<bool>> states(len+1, vector<bool>(target+1, false));
        states[0][0] = true;
        for (int i=1; i<=len; i++) {
            for (int j=1; j<=target; j++) {
                if (j - nums[i-1] < 0) {
                    states[i][j] = states[i-1][j];
                } else {
                    states[i][j] = states[i-1][j] || states[i-1][j-nums[i-1]];
                }
            }
            // prune
            if (states[i][target]) return true;
        }
        return states.back().back();
    }

};
// @lc code=end

