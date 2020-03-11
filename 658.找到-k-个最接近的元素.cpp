/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // solution one (v2)
        // siliding window starting from beginning
        // 复杂度o(n)
        // vector<int> window;
        // int p = k-1, i = 0;
        // while (i < k) {
        //     window.push_back(abs(arr[i] - x));
        //     i++;
        // }
        // while (i < arr.size()) {
        //     window.push_back(abs(arr[i] - x));
        //     if (window.back() < window[0]) {
        //         p = i;
        //     }
        //     window.erase(window.begin());
        //     i++;
        // }
        // vector<int> res;
        // for (int i=p-k+1; i<=p; i++) res.push_back(arr[i]);
        // return res;

        // solution two (v2)
        // first find x in the arr
        // then check the ranges aroud it
        // int l = 0, r = arr.size(), mid;
        // while (l < r) {
        //     mid = l + (r - l) / 2;
        //     if (arr[mid] < x) {
        //         l = mid + 1;
        //     } else {
        //         r = mid;
        //     }
        // }
        // // check the range l-k ~ l
        // int left = min(max(0, l-k), int(arr.size())-k), p = left;
        // vector<int> window;
        // int counter = 0;
        // while (counter < k) {
        //     window.push_back(abs(arr[left+counter]-x));
        //     counter++;
        // }
        // while (left <= l && left+k < arr.size()) {
        //     window.push_back(abs(arr[left+k]-x));
        //     if (window.back() < window[0]) {
        //         p = left+1;
        //     }
        //     window.erase(window.begin());
        //     left++;
        // }
        // return vector<int>(arr.begin()+p, arr.begin()+p+k);

        // solution three (v2)
        // Ref.:https://leetcode-cn.com/problems/find-k-closest-elements/solution/658-zhao-dao-k-ge-zui-jie-jin-de-yuan-su-cer-fen-s/
        // 将问题转化为寻找最优区间的左边界。考虑要在长度为k+1的区间中排除一个元素，
        // 如果左边界到x的距离比右边界到x的距离大，则除掉左边界
        // 如果左边界到x的距离比右边界到x的距离小，则除掉右边界
        // 如果左边界到x的距离与右边界到x的距离相等，则除掉右边界
        vector<int> res;
        // 长度为k+1的最优区间的左边界的最大值为arr.size() - k
        int left = 0, right = arr.size() - k, mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            // // target在长度为k+1的区间之外
            // if (arr[mid+k] < x) {
            //     left = mid + 1;
            // } else if (arr[mid] >= x) {
            //     right = mid;
            // // // target在长度为k+1的区间之内
            // } else if (x-arr[mid] > arr[mid+k]-x) {
            //     left = mid + 1;
            // } else {
            //     right = mid;
            // }
            
            //以上四个条件判断可以简化为以下两个：
            if (x-arr[mid] > arr[mid+k]-x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return vector<int>(arr.begin()+left, arr.begin()+left+k);

    }
};
// @lc code=end

