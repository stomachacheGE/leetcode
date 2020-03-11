/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
private:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        // brute force
        // unordered_set<int> set;
        // set.insert(n);
        // while (n != 1) {
        //     int temp = 0;
        //     while (n) {
        //         temp += (n % 10) * (n % 10);
        //         n /= 10;
        //     }
        //     n = temp;
        //     if (set.count(n)) break;
        //     set.insert(n);
        // }
        // return n == 1;
    
        // solution two
        // 快慢指针
        // ref.:https://leetcode-cn.com/problems/happy-number/solution/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/
        int slow = n, fast = n;
        while (true) {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
            if (fast == 1) return true;
            if (fast == slow) break;
        }
        return false;
    }
};
// @lc code=end

