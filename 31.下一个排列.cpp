/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
public:
    void nextPermutation1(vector<int>& nums) {

        // Solution One
        // 从最后一个数往前，
        // 找到每个数其前面第一个比它大的数，记录它的位置
        // 记录中位置最靠后的对应的那两个数
        // 将后面的数调换到前面后，对剩下的数进行排序

        // int i = -1, j = -1;
        // for (int m=nums.size()-1; m>=1; m--) {
        //     for (int n=m-1; n>=0; n--) {
        //         if (nums[n] < nums[m]) {
        //             if (n > i) {  // 注意我们需要找位置最靠后的两个，所以需要完全遍历
        //                 i = n;
        //                 j = m;
        //             }
        //         }
        //     }
        // }

        // if (i != -1) {
        //     int temp = nums[i];
        //     nums[i] = nums[j];
        //     nums[j] = temp;
        //     sort(nums.begin()+i+1, nums.end());
        // } else {
        //     reverse(nums.begin(), nums.end());
        // }
        
        // Solution Two
        // Ref.:https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode/
        int idx = -1;
        for (int i=nums.size()-1; i>=1; i--) {
            if (nums[i-1] < nums[i]) {
                idx = i-1;
                break;
            }
        }

        if (idx == -1) {
            reverse(nums, 0, nums.size()-1);
        } else {
            int i = nums.size() - 1;
            for (; i>idx; i--) {
                if (nums[i] > nums[idx]) {
                    break;
                }
            }
            swap(nums, idx, i);
            reverse(nums, idx+1, nums.size()-1);
        }
    }

    void nextPermutation(vector<int>& nums) {
        int i = -1, j = -1;
        for (int m=nums.size()-1; m>=1; m--) {
            for (int n=m-1; n>=0; n--) {
                if (nums[n] < nums[m]) {
                    if (n > i) {  // 注意我们需要找位置最靠后的两个，所以需要完全遍历
                        i = n;
                        j = m;
                    }
                }
            }
        }

         if (i == -1) {
            reverse(nums, 0, nums.size()-1);
        } else {
            swap(nums, i, j);
            reverse(nums, i+1, nums.size()-1);
        }
    }
};
// @lc code=end

