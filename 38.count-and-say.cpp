/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (40.38%)
 * Total Accepted:    285.7K
 * Total Submissions: 703.6K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
public:
    // 100%, 29.5%
    string countAndSay(int n) {
        if (n==1) return "1";
        string ret_1 = countAndSay(n-1);
        string ret;
        char cur = ret_1[0];
        int count = 0;
        for (int i=0; i<ret_1.size(); i++) {
            if (ret_1[i] == cur) {
                count++;
                continue;
            }

            ret.push_back(count+'0');
            ret.push_back(cur);
            cur = ret_1[i];
            count = 1;
        }

        ret.push_back(count+'0');
        ret.push_back(cur);
        return ret;
    }
};
