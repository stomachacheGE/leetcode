/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Solution one
        // naive implementation with two pointers
        // if (nums.size() <= 2) return nums.size();
        // int counter = 0, ahead = 0, behind = 0, end = nums.size()-1;
        // while (ahead <= end) {
        //     while (ahead < end && nums[ahead+1] == nums[ahead]) {
        //         ahead++;
        //     }
        //     if (ahead - behind + 1 <= 2) {
        //         // cout << nums[ahead] << " has " << ahead - behind + 1 << " ele, not moving" << endl;
        //         counter += ahead - behind + 1;
        //         behind = ++ahead;
        //     } else {
        //         // cout << nums[ahead] << " has " << ahead - behind + 1 << " ele, moving" << endl;
        //         int i = behind + 2;
        //         // int j = ahead + 1;
        //         // while (j <= end) {
        //         //     nums[i++] = nums[j++];
        //         // }
        //         // 以上的覆盖可以用以下的删除元素替代
        //         while (i++ <= ahead) {
        //             nums.erase(nums.begin()+behind+2);
        //         }
        //         end -= (ahead - behind + 1) - 2;
        //         behind += 2;
        //         ahead = behind;
        //         counter += 2;
        //     }
        //     // cout << "ahead=" << ahead << ", behind=" << behind << ", end=" << end << ", counter=" << counter << endl;
        // }
        // return counter;

        // Solution two
        // Ref.:https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-xiang-i-7/
        // 两个pointer，ahead指针按顺序遍历，behind指针指向处理后的位置
        // 每走一步，得到当前数的计数
        // 如果小于等于2，将ahead指针的值覆盖到behind指针上，并累加ahead和behind指针
        // 如果大于2，只移动ahead指针
        // if (nums.size() <= 2) return nums.size();
        // int ahead = 0, behind = 0, counter = 0;
        // while (ahead < nums.size()) {
        //     if (ahead >= 1 && nums[ahead] == nums[ahead-1]) {
        //         counter++;
        //     } else {
        //         counter = 1;
        //     }

        //     if (counter <= 2) {
        //         nums[behind] = nums[ahead];
        //         behind++;
        //     }
        //     ahead++;
        // }
        // return behind;

        // solution one (v1)
        // 不用两个指针，通过删除动态改变nums的大小
        if (nums.size() <= 1) return nums.size();
        int i = 0, counter = 0;
        while (i < nums.size()) {

            bool deleted = false;
            while (i > 0 && i < nums.size() && counter == 2 && nums[i] == nums[i-1]) {
                nums.erase(nums.begin()+i);
                deleted = true;
            }
            if (deleted) continue;

            if (i > 0 && i < nums.size() && nums[i] == nums[i-1]) {
                counter++;
            } else {
                counter = 1;
            }
            i++;
        }
        return nums.size();
    }
};
// @lc code=end

