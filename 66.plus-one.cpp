/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.15%)
 * Total Accepted:    390.2K
 * Total Submissions: 947.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        ////////// Solution One (Me) //////////
        // Naive implementation. Not memory efficient.
        // std::vector<int> res;
        // int carry = 1;
        // int size = digits.size();
        // for (int i=size-1; i>=0; i--) {
        //     int sum = digits[i] + carry;
        //     carry = sum / 10;
        //     digits[i] = sum % 10;
        // }

        // if (carry == 1) res.push_back(1);
        // for (int i=0; i<size; i++) res.push_back(digits[i]);
        // return res;

        ////////// Solution Two //////////
        // Ref.:https://leetcode.com/problems/plus-one/discuss/24122
        bool carry = true;
        for (int i=digits.size()-1; i>=0 && carry; i--)
            carry = (digits[i] = ++digits[i]%10) == 0;
        
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
