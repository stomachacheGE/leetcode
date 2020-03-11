/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.98%)
 * Total Accepted:    308K
 * Total Submissions: 782.8K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
private:
    char add(char a, char b, bool& carry) {
        int value = a+b+carry-2*'0';
        // char ret;
        // switch (value) {
        //   case 0: carry=false; ret='0'; break;
        //   case 1: carry=false; ret='1'; break;
        //   case 2: carry=true; ret='0'; break;
        //   case 3: carry=true; ret='1'; break;
        // }

        // a simpler version
        carry = value / 2;
        return value % 2 + '0';
    }

public:
    string addBinary(string a, string b) {

        ////////// Solution One //////////
        // 93.32%, 69.84%
        // bool carry = false;
        // int idx_a = a.size()-1, idx_b = b.size()-1;
        // string ret;
        // while (idx_a>=0 && idx_b>=0) ret.insert(0, 1, add(a[idx_a--], b[idx_b--], carry));
        // while (idx_a>=0) ret.insert(0, 1, add(a[idx_a--], '0', carry));
        // while (idx_b>=0) ret.insert(0, 1, add(b[idx_b--], '0', carry));
        // if (carry) ret.insert(0, 1, '1');
        // return ret;

        ////////// Solution Two //////////
        // 100%, 70.4%
        // Ref.: https://leetcode.com/problems/add-binary/discuss/24475/Short-code-by-c%2B%2B
        // cleaner version, and maybe more memory effcient
        // the key idea is not to prepend the final string for each step,
        // but reverse the final string just before return.
        // see discussion for more details.
        int carry = 0;
        int idx_a = a.size()-1, idx_b = b.size()-1;
        string ret;
        while (idx_a>=0 || idx_b>=0 || carry) {
            if (idx_a >=0) carry += a[idx_a--] - '0';
            if (idx_b >=0) carry += b[idx_b--] - '0';
            ret += carry % 2 + '0';
            carry /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;


    }
};
