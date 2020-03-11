/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.26%)
 * Total Accepted:    270.9K
 * Total Submissions: 839.4K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {

        ////////// Solution One //////////
        // 89.60%， 80.39%
        if (s.size() == 0) return 0;
        int last_count = s.size() - 1;
        while (s[last_count] == ' ') last_count -=1;
        int ret = 0;
        for (int i=last_count; i>=0; i--) {
            if (s[i] == ' ') break;
            ret++;
        }
        return ret;

        ////////// Solution Two //////////
        // cleaner version, same idea
        if (s.size() == 0) return 0;
        int ret=0, tail = s.size() - 1;
        while(tail >=0 && s[tail] == ' ') tail--;
        while(tail >=0 && s[tail] != ' ') {
            tail--;
            len++;
        }
        return len;

    }
};
