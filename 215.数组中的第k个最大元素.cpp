/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
private:    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
        return;
    }
    
    int helper_v2(vector<int>& nums, int start, int end, int k) {
        // 如果范围交叉，则说明中位数已经在它的位置上，直接返回中位数
        if (start >= end) return nums[k];
        
        // partition
        int mid = start + (end - start) / 2;
        // pivot is necessary, bacause nums[mid] changes
        int pivot = nums[mid];
        swap(nums[mid], nums[end]);
        int i = start-1;
        for (int j=start; j<=end-1; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        
        swap(nums[++i], nums[end]);
        

        if (k < i) {
            return helper_v2(nums, start, i-1, k);
        } 
        if (k > i) {
            return helper_v2(nums, i+1, end, k);
        }
        
        return nums[k];
    }

    int partition(vector<int>& nums, int start, int end) {
        int num = nums[end];
        int i = start, j = start, temp;
        while (j < end) {

            if (nums[j] >= num) {
                j++;
                continue;
            }
            if (i != j) {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
            i++;
            j++;
        }
        nums[end] = nums[i];
        nums[i] = num;
        return i;
    }

    int partition1(vector<int>& nums, int start, int end) {
        int num = nums[end];
        int i = start, j = start, temp;
        while (j <= end) {
            
            if (nums[j] <= num) { 
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
            }
            j++;
        }

        // nums[end] = nums[i];
        // nums[i] = num;
        return i-1;
    }

     int partition2(vector<int>& nums, int start, int end) {
        int num = nums[end];
        int i = start, j = start, temp;
        while (j < end) {
            
            if (nums[j] < num) { 
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
            }
            j++;
        }

        nums[end] = nums[i];
        nums[i] = num;
        return i;
     }
public:
    int findKthLargest1(vector<int>& nums, int k) {
        
        int len = nums.size();
        return helper_v2(nums, 0, len-1, len-k);
        
    }

    int findKthLargest(vector<int>& nums, int k) {

        // solution one
        // parition
        int idx = -1;
        k = nums.size() - k;
        int start = 0, end = nums.size()-1;
        while (idx != k) {
            idx = partition1(nums, start, end);
            if (idx == k) return nums[idx];
            else if (idx < k) {
                start = idx + 1;
            } else {
                end = idx - 1;
            }
        }
        return 0;

        // solution two
        // min_heap
        // priority_queue<int, vector<int>, greater<int>> min_heap;
        // for (auto &num: nums) {
        //     min_heap.push(num);
        //     if (min_heap.size() > k) min_heap.pop();
        // }
        // return min_heap.top();
    }
};
// @lc code=end

