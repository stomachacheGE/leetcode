/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        // solution one
        // ref.:https://leetcode-cn.com/problems/wiggle-sort-ii/solution/yi-bu-yi-bu-jiang-shi-jian-fu-za-du-cong-onlognjia/
        int len = nums.size();
        quickSelect(nums, 0, len-1, len / 2);
        auto midptr = nums.begin() + len / 2;
        int mid = *midptr;
        
        // 3-way-partition
        int i = 0, j = 0, k = nums.size() - 1;
        while(j < k){
            if(nums[j] > mid){
                swap(nums[j], nums[k]);
                --k;
            } else if(nums[j] < mid){
                swap(nums[j], nums[i]);
                ++i;
                ++j;
            }
            else{
                ++j;
            }
        }
        
        if(nums.size() % 2) ++midptr;
        vector<int> tmp1(nums.begin(), midptr);
        vector<int> tmp2(midptr, nums.end());
        for(int i = 0; i < tmp1.size(); ++i){
            nums[2 * i] = tmp1[tmp1.size() - 1 - i];
        }
        for(int i = 0; i < tmp2.size(); ++i){
            nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
        }
    }
    
private:
    void quickSelect(vector<int> &nums, int begin, int end, int n){
        if (begin > end) return;
        int t = nums[end];
        int i = begin, j = begin;
        while(j <= end){
            if(nums[j] <= t){
                swap(nums[i++], nums[j++]);
            }
            else{
                ++j;
            }
        }
        if(i > n){
            quickSelect(nums, begin, i-2 , n); // 注意是i-2
        } else if (i < n){
            quickSelect(nums, i, end, n);
        }
    }
};
// @lc code=end

